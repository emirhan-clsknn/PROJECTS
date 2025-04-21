package HWSystem;

import HWSystem.Devices.*;
import HWSystem.Protocols.*;
import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class HWSystem {

    private ArrayList<Protocol> protocols;
    private ArrayList<Device> devices;
    private ArrayList<MotorDriver> motorDrivers;
    private ArrayList<WirelessIO> wirelessIOs;
    private ArrayList<Sensor> sensors;
    private ArrayList<Display> displays;
    private int numberOfMotors;
    private int numberOfWireless;
    private int numberOfSensors;
    private int numberOfDisplays;

    private int totalPort;

    /**
     * Reads the configuration from the given file and initializes the devices
     * and protocols.
     *
     * @param filename the name of the configuration file
     * @param logDir the directory for logging data
     */
    public void readConfig(String filename, String logDir) {
        String filePath = filename;
        LinkedList<String> protocolsClasses = new LinkedList<>();
        LinkedList<Integer> variables = new LinkedList<>();

        try (Scanner scanner = new Scanner(new File(filePath))) {

            // Read the first line for protocols
            if (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(":");
                if (parts.length > 1) {
                    String[] protocols = parts[1].split(",");
                    Iterator<String> iterator = Arrays.asList(protocols).iterator();
                    while (iterator.hasNext()) {
                        protocolsClasses.add(iterator.next().trim());
                    }
                }
            }

            // Read the remaining lines for variables (device counts)
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(":");
                if (parts.length > 1) {
                    try {
                        int value = Integer.parseInt(parts[1].trim());
                        variables.add(value);
                    } catch (NumberFormatException e) {
                        System.err.println("Wrong number format: " + line);
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
            return;
        }

        // Initialize device counts
        Iterator<Integer> varIterator = variables.iterator();
        this.numberOfSensors = varIterator.hasNext() ? varIterator.next() : 0;
        this.numberOfDisplays = varIterator.hasNext() ? varIterator.next() : 0;
        this.numberOfWireless = varIterator.hasNext() ? varIterator.next() : 0;
        this.numberOfMotors = varIterator.hasNext() ? varIterator.next() : 0;
        this.totalPort = this.numberOfDisplays + this.numberOfWireless + this.numberOfMotors + this.numberOfSensors;

        // Initialize lists
        this.protocols = new ArrayList<>();
        this.devices = new ArrayList<>();
        this.sensors = new ArrayList<>();
        this.motorDrivers = new ArrayList<>();
        this.wirelessIOs = new ArrayList<>();
        this.displays = new ArrayList<>();

        // Initialize protocols based on the configuration file
        Iterator<String> protocolIterator = protocolsClasses.iterator();
        int i = 0;
        while (protocolIterator.hasNext()) {
            devices.add(null);
            String protocol = protocolIterator.next();
            switch (protocol) {
                case "UART":
                    protocols.add(new UART(i, logDir));
                    break;
                case "SPI":
                    protocols.add(new SPI(i, logDir));
                    break;
                case "I2C":
                    protocols.add(new I2C(i, logDir));
                    break;
                case "OneWire":
                    protocols.add(new OneWire(i, logDir));
                    break;
            }
            i++;
        }
    }

    /**
     * Adds a device to the system at the specified port and assigns it an ID.
     *
     * @param dvname The name of the device to add (e.g., "Bluetooth", "BME280",
     * etc.).
     * @param port The port number to which the device will be connected.
     * @param id The unique ID of the device.
     */
    public void addDevice(String dvname, int port, int id) {
        if (port >= 0 && port < this.totalPort && id >= 0) {
            if (devices.get(port) == null) {
                WirelessIO dvc1 = null;
                Sensor dvc2 = null;
                MotorDriver dvc3 = null;
                Display dvc4 = null;
                String devType = "";

                // Determine the device type based on the device name
                switch (dvname) {
                    case "Bluetooth":
                        dvc1 = new Bluetooth(protocols.get(port));
                        devType = "WirelessIO";
                        break;
                    case "BME280":
                        dvc2 = new BME280(protocols.get(port));
                        devType = "Sensor";
                        break;
                    case "DHT11":
                        dvc2 = new DHT11(protocols.get(port));
                        devType = "Sensor";
                        break;
                    case "GY951":
                        dvc2 = new GY951(protocols.get(port));
                        devType = "Sensor";
                        break;
                    case "LCD":
                        dvc4 = new LCD(protocols.get(port));
                        devType = "Display";
                        break;
                    case "OLED":
                        dvc4 = new OLED(protocols.get(port));
                        devType = "Display";
                        break;
                    case "MPU6050":
                        dvc2 = new MPU6050(protocols.get(port));
                        devType = "Sensor";
                        break;
                    case "PCA9685":
                        dvc3 = new PCA9685(protocols.get(port));
                        devType = "MotorDriver";
                        break;
                    case "SparkFunMD":
                        dvc3 = new SparkFunMD(protocols.get(port));
                        devType = "MotorDriver";
                        break;
                    case "Wifi":
                        dvc1 = new Wifi(protocols.get(port));
                        devType = "WirelessIO";
                        break;
                    default:
                        break;
                }

                // Add the device to the corresponding list based on its type
                switch (devType) {
                    case "WirelessIO":
                        if (this.numberOfWireless > 0) {
                            if (dvc1.getProtocol()) {
                                if (id == wirelessIOs.size()) {
                                    dvc1.setPortId(port);
                                    dvc1.setDevId(id);
                                    devices.set(port, dvc1);
                                    wirelessIOs.add(dvc1);
                                    --this.numberOfWireless;
                                    System.out.println("Device added.");
                                } else if (id < wirelessIOs.size()) {
                                    if (wirelessIOs.get(id) == null) {
                                        dvc1.setPortId(port);
                                        dvc1.setDevId(id);
                                        devices.set(port, dvc1);
                                        wirelessIOs.set(id, dvc1);
                                        --this.numberOfWireless;
                                        System.out.println("Device added.");
                                    }
                                } else {
                                    System.err.println("This id is already occupied or out of bounds.");
                                }
                            }
                        } else {
                            System.err.println("No more WirelessIO available.");
                        }
                        break;

                    case "Sensor":
                        if (this.numberOfSensors > 0) {
                            if (dvc2.getProtocol()) {
                                if (id == sensors.size()) {
                                    dvc2.setPortId(port);
                                    dvc2.setDevId(id);
                                    devices.set(port, dvc2);
                                    sensors.add(dvc2);
                                    --this.numberOfSensors;
                                    System.out.println("Device added.");
                                } else if (id < sensors.size()) {
                                    if (sensors.get(id) == null) {
                                        dvc2.setPortId(port);
                                        dvc2.setDevId(id);
                                        devices.set(port, dvc2);
                                        sensors.set(id, dvc2);
                                        --this.numberOfSensors;
                                        System.out.println("Device added.");
                                    }
                                } else {
                                    System.err.println("This id is already occupied or out of bounds.");
                                }
                            }
                        } else {
                            System.err.println("No more Sensor available.");
                        }
                        break;

                    case "Display":
                        if (this.numberOfDisplays > 0) {
                            if (dvc4.getProtocol()) {
                                if (id == displays.size()) {
                                    dvc4.setPortId(port);
                                    dvc4.setDevId(id);
                                    devices.set(port, dvc4);
                                    displays.add(dvc4);
                                    --this.numberOfDisplays;
                                    System.out.println("Device added.");
                                } else if (id < displays.size()) {
                                    if (displays.get(id) == null) {
                                        dvc4.setPortId(port);
                                        dvc4.setDevId(id);
                                        devices.set(port, dvc4);
                                        displays.set(id, dvc4);
                                        --this.numberOfDisplays;
                                        System.out.println("Device added.");
                                    }
                                } else {
                                    System.err.println("This id is already occupied or out of bounds.");
                                }
                            }
                        } else {
                            System.err.println("No more Displays available.");
                        }
                        break;

                    case "MotorDriver":
                        if (this.numberOfMotors > 0) {
                            if (dvc3.getProtocol()) {
                                if (id == motorDrivers.size()) {
                                    dvc3.setPortId(port);
                                    dvc3.setDevId(id);
                                    devices.set(port, dvc3);
                                    motorDrivers.add(dvc3);
                                    --this.numberOfMotors;
                                    System.out.println("Device added.");
                                } else if (id < motorDrivers.size()) {
                                    if (motorDrivers.get(id) == null) {
                                        dvc3.setPortId(port);
                                        dvc3.setDevId(id);
                                        devices.set(port, dvc3);
                                        motorDrivers.set(id, dvc3);
                                        --this.numberOfMotors;
                                        System.out.println("Device added.");
                                    }
                                } else {
                                    System.err.println("This id is already occupied or out of bounds.");
                                }
                            }
                        } else {
                            System.err.println("No more motor drivers available.");
                        }
                        break;

                    default:
                        System.err.println("Invalid device type.");
                }

            } else {
                System.err.println("Port " + port + " is already occupied.");
            }
        } else {
            System.err.println("Invalid port number.");
        }
    }

    /**
     * Removes a device from the specified port in the system.
     *
     * @param port The port number from which the device will be removed.
     */
    public void removeDevice(int port) {

        if (port >= 0 && port < this.totalPort) {
            if (devices.get(port) != null) {
                // Check if the device is ON, it must be turned OFF first before removal
                if (devices.get(port).getState() != State.OFF) {
                    System.err.println("Device is ON please turn off first.");
                    return;
                }

                String devType = devices.get(port).getDevType();

                // Remove the device based on its type
                if (devType.equals("WirelessIO")) {
                    wirelessIOs.set(devices.get(port).getDevId(), null);
                    devices.set(port, null);

                    this.numberOfWireless++;
                    System.out.println("Device removed.");
                } else if (devType.equals("Sensor")) {
                    sensors.set(devices.get(port).getDevId(), null);
                    devices.set(port, null);
                    this.numberOfSensors++;
                    System.out.println("Device removed.");
                } else if (devType.equals("Display")) {
                    displays.set(devices.get(port).getDevId(), null);
                    devices.set(port, null);
                    this.numberOfDisplays++;
                    System.out.println("Device removed.");
                } else if (devType.equals("MotorDriver")) {
                    motorDrivers.set(devices.get(port).getDevId(), null);
                    devices.set(port, null);
                    this.numberOfMotors++;
                    System.out.println("Device removed.");
                } else {
                    System.err.println("Invalid device type.");
                }

            } else {
                System.err.println("This port is already empty.");
            }
        } else {
            System.err.println("Invalid port number.");
        }
    }

    /**
     * Lists all the ports in the system along with the associated devices,
     * their protocol type, device type, and current state. If the port is
     * empty, it will be marked as "empty", otherwise it will display details
     * about the device occupying the port.
     */
    public void listPorts() {
        System.out.println("list of ports:");

        // Iterator to go through all devices in the system
        Iterator<Device> deviceIterator = devices.iterator();
        int i = 0;

        while (deviceIterator.hasNext()) {
            Device device = deviceIterator.next();

            // Print the port index and its associated protocol
            System.out.print(i + " ");
            System.out.print(protocols.get(i).getProtocolName() + " ");

            if (device == null) {
                // If the port is empty, mark it as such
                System.out.println("empty");
            } else {
                // If the port is occupied, display the device's name and type
                System.out.print("occupied " + device.getName() + " ");

                // If the device is a Sensor, display additional sensor information
                if ("Sensor".equals(device.getDevType())) {
                    System.out.print(sensors.get(device.getDevId()).getSensType() + " "
                            + sensors.get(device.getDevId()).getDevType() + " "
                            + sensors.get(device.getDevId()).getDevId() + " ");
                } else {
                    // For non-sensor devices, display the device type and ID
                    System.out.print(device.getDevType() + " " + device.getDevId() + " ");
                }

                // Display the device's current state
                System.out.println(device.getState());
            }
            i++;
        }
    }

    /**
     * Lists all devices of a specified type in the system (Sensor, Display,
     * MotorDriver, or WirelessIO). For each device, it displays its name,
     * device ID, port ID, and the protocol associated with that port.
     *
     * @param dev The type of device to list. It can be "Sensor", "Display",
     * "MotorDriver", or "WirelessIO".
     */
    public void listDevices(String dev) {
        System.out.println("list of " + dev + "s:");

        // List all Sensors if the requested device type is "Sensor"
        if ("Sensor".equals(dev)) {
            Iterator<Sensor> sensorIterator = sensors.iterator();
            while (sensorIterator.hasNext()) {
                Sensor sensor = sensorIterator.next();

                // Print sensor details: name, device ID, port ID, and associated protocol
                System.out.println(sensor.getName() + " " + sensor.getDevId() + " "
                        + sensor.getPortId() + " "
                        + protocols.get(sensor.getPortId()).getProtocolName());
            }
        } // List all Displays if the requested device type is "Display"
        else if ("Display".equals(dev)) {
            Iterator<Display> displayIterator = displays.iterator();

            while (displayIterator.hasNext()) {
                Display display = displayIterator.next();

                // Print display details: name, device ID, port ID, and associated protocol
                System.out.println(display.getName() + " " + display.getDevId() + " "
                        + display.getPortId() + " "
                        + protocols.get(display.getPortId()).getProtocolName());
            }
        } // List all MotorDrivers if the requested device type is "MotorDriver"
        else if ("MotorDriver".equals(dev)) {
            Iterator<MotorDriver> motorDriverIterator = motorDrivers.iterator();

            while (motorDriverIterator.hasNext()) {
                MotorDriver motorDriver = motorDriverIterator.next();
                // Print motor driver details: name, device ID, port ID, and associated protocol
                System.out.println(motorDriver.getName() + " " + motorDriver.getDevId() + " "
                        + motorDriver.getPortId() + " "
                        + protocols.get(motorDriver.getPortId()).getProtocolName());
            }
        } // List all WirelessIOs if the requested device type is "WirelessIO"
        else if ("WirelessIO".equals(dev)) {
            Iterator<WirelessIO> wirelessIterator = wirelessIOs.iterator();

            while (wirelessIterator.hasNext()) {
                WirelessIO wireless = wirelessIterator.next();

                // Print wireless IO details: name, device ID, port ID, and associated protocol
                System.out.println(wireless.getName() + " " + wireless.getDevId() + " "
                        + wireless.getPortId() + " "
                        + protocols.get(wireless.getPortId()).getProtocolName());
            }
        }
    }

    /**
     * Turns on the device at the specified port. The device must exist at the
     * given port and be of a valid type. If the port is valid and the device is
     * not empty, the device will be powered on. The protocol associated with
     * the port will also send a "turnON" command.
     *
     * @param port The port number of the device to turn on.
     */
    public void turnOnDevice(int port) {
        // Check if the port number is valid
        if (port >= 0 && port < devices.size()) {
            if (devices.get(port) == null) {
                System.err.println("This port is empty.");
                return;
            }
            devices.get(port).turnON(); // Turn on the device
            protocols.get(port).write("turnON"); // Send the "turnON" command to the protocol
        } else {
            System.err.println("Invalid port number.");
        }
    }

    /**
     * Turns off the device at the specified port. The device must exist at the
     * given port and be of a valid type. If the port is valid and the device is
     * not empty, the device will be powered off. The protocol associated with
     * the port will also send a "turnOFF" command.
     *
     * @param port The port number of the device to turn off.
     */
    public void turnOffDevice(int port) {
        // Check if the port number is valid
        if (port >= 0 && port < devices.size()) {
            if (devices.get(port) == null) {
                System.err.println("This port is empty.");
                return;
            }
            devices.get(port).turnOFF(); // Turn off the device
            protocols.get(port).write("turnOFF"); // Send the "turnOFF" command to the protocol
        } else {
            System.err.println("Invalid port number.");
        }
    }

    /**
     * Reads data from the sensor at the specified port. The sensor must be in
     * an ON state in order to read data. If the sensor is OFF or the port is
     * invalid, an error message is printed. The protocol associated with the
     * sensor's port will also attempt to read data.
     *
     * @param port The port number of the sensor to read data from.
     */
    public void readSensor(int port) {
        // Check if the port number is valid
        if (port >= 0 && port < sensors.size()) {
            if (sensors.get(port) == null) {
                System.err.println("There is not device with this id.");
                return;
            }
            // Check if the sensor is ON
            if (sensors.get(port).getState() == State.OFF) {
                System.err.println("Device is OFF. Cannot read data.");
                return;
            }
            // Print the sensor's information and data
            System.out.println(sensors.get(port).getName() + " " + sensors.get(port).getSensType() + " " + sensors.get(port).getDevType() + ": " + sensors.get(port).data2String());
            // Use the protocol to read the sensor data
            protocols.get(sensors.get(port).getPortId()).read();
        } else {
            System.err.println("Invalid devId number or Device is OFF.");
        }
    }

    /**
     * Prints data to the display at the specified port. The display must be in
     * an ON state in order to print data. If the display is OFF or the port is
     * invalid, an error message is printed. The data is also sent to the
     * protocol associated with the display's port.
     *
     * @param port The port number of the display to print data on.
     * @param data The data to be printed on the display.
     */
    public void printData(int port, String data) {

        // Check if the port number is valid
        if (port >= 0 && port < displays.size()) {
            if (displays.get(port) == null) {
                System.err.println("There is not device with this id.");
                return;
            }
            // Check if the display is ON
            if (displays.get(port).getState() == State.OFF) {
                System.err.println("Device is OFF. Cannot read data.");
                return;
            }
            // Print the data on the display
            displays.get(port).printData(data);
            // Send the data to the protocol
            protocols.get(displays.get(port).getPortId()).write(data);

        } else {
            System.err.println("Invalid devId number or Device is OFF.");
        }
    }

    /**
     * Changes the speed of the motor at the specified port. The motor must be
     * in an ON state in order to change its speed. If the motor is OFF or the
     * port is invalid, an error message is printed. The new speed is sent to
     * the protocol associated with the motor's port.
     *
     * @param port The port number of the motor to change speed.
     * @param speed The new speed to be set for the motor.
     */
    public void changeMotorSpeed(int port, int speed) {

        // Check if the port number is valid
        if (port >= 0 && port < motorDrivers.size()) {
            if (motorDrivers.get(port) == null) {
                System.err.println("There is not device with this id.");
                return;
            }
            // Check if the motor is ON
            if (motorDrivers.get(port).getState() == State.OFF) {
                System.err.println("Device is OFF. Cannot read data.");
                return;
            }
            // Set the motor speed
            motorDrivers.get(port).setMotorSpeed(10);
            // Send the new speed to the protocol
            protocols.get(motorDrivers.get(port).getPortId()).write("" + speed + "");

        } else {
            System.err.println("Invalid devId number or Device is OFF.");
        }
    }

    /**
     * Sends data to the wireless I/O device at the specified port. The device
     * must be in an ON state in order to send data. If the device is OFF or the
     * port is invalid, an error message is printed. The data is sent to the
     * wireless device and also passed to the associated protocol for
     * transmission.
     *
     * @param port The port number of the wireless I/O device to send data.
     * @param data The data to be sent to the wireless device.
     */
    public void sndData(int port, String data) {
        // Check if the port number is valid
        if (port >= 0 && port < wirelessIOs.size()) {
            if (wirelessIOs.get(port) == null) {
                System.err.println("There is not device with this id.");
                return;
            }
            // Check if the device is ON
            if (wirelessIOs.get(port).getState() == State.OFF) {
                System.err.println("Device is OFF. Cannot read data.");
                return;
            }
            // Send the data to the wireless device
            wirelessIOs.get(port).sendData(data);
            // Send the data to the protocol for transmission
            protocols.get(wirelessIOs.get(port).getPortId()).write(data);
        } else {
            System.err.println("Invalid devId number or Device is OFF.");
        }
    }

    /**
     * Receives data from the wireless I/O device at the specified port. The
     * device must be in an ON state in order to receive data. If the device is
     * OFF or the port is invalid, an error message is printed. The received
     * data is printed to the console and also passed to the associated protocol
     * for reading.
     *
     * @param port The port number of the wireless I/O device from which to
     * receive data.
     */
    public void revData(int port) {
        // Check if the port number is valid
        if (port >= 0 && port < wirelessIOs.size()) {
            if (wirelessIOs.get(port) == null) {
                System.err.println("There is not device with this id.");
                return;
            }
            // Check if the device is ON
            if (wirelessIOs.get(port).getState() == State.OFF) {
                System.err.println("Device is OFF. Cannot read data.");
                return;
            }
            // Print the received data from the wireless device
            System.out.println(wirelessIOs.get(port).recvData());

            // Read data from the protocol
            protocols.get(wirelessIOs.get(port).getPortId()).read();
        } else {
            System.err.println("Invalid devID number or Device is OFF.");
        }
    }

    /**
     * Closes all active protocols when the system is exiting. This method
     * iterates through the list of protocols and calls the close method on each
     * one to release resources and ensure proper shutdown.
     */
    public void exitting() {
        Iterator<Protocol> protocolIterator = protocols.iterator();
        while (protocolIterator.hasNext()) {
            Protocol protocol = protocolIterator.next();
            protocol.close();  // Close each protocol to release resources
        }
    }

}
