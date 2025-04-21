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

    public void readConfig(String filename, String logDir) {
        String filePath = filename;
        LinkedList<String> protocolsClasses = new LinkedList<>();
        LinkedList<Integer> variables = new LinkedList<>();

        try (Scanner scanner = new Scanner(new File(filePath))) {

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

        Iterator<Integer> varIterator = variables.iterator();
        this.numberOfSensors = varIterator.hasNext() ? varIterator.next() : 0;
        this.numberOfDisplays = varIterator.hasNext() ? varIterator.next() : 0;
        this.numberOfWireless = varIterator.hasNext() ? varIterator.next() : 0;
        this.numberOfMotors = varIterator.hasNext() ? varIterator.next() : 0;
        this.totalPort = this.numberOfDisplays + this.numberOfWireless + this.numberOfMotors + this.numberOfSensors;
        this.protocols = new ArrayList<>();
        this.devices = new ArrayList<>();
        this.sensors = new ArrayList<>();
        this.motorDrivers = new ArrayList<>();
        this.wirelessIOs = new ArrayList<>();
        this.displays = new ArrayList<>();

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

    public void addDevice(String dvname, int port, int id) {
        if (port >= 0 && port < this.totalPort && id >= 0) {
            if (devices.get(port) == null) {
                WirelessIO dvc1 = null;
                Sensor dvc2 = null;
                MotorDriver dvc3 = null;
                Display dvc4 = null;
                String devType = "";
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

    public void removeDevice(int port) {

        if (port >= 0 && port < this.totalPort) {
            if (devices.get(port) != null) {
                if (devices.get(port).getState() != State.OFF) {
                    System.err.println("Device is ON please turn off first.");
                    return;
                }
                String devType = devices.get(port).getDevType();

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

    public void listPorts() {
        System.out.println("list of ports:");

        Iterator<Device> deviceIterator = devices.iterator();
        int i = 0;

        while (deviceIterator.hasNext()) {

            Device device = deviceIterator.next();

            System.out.print(i + " ");
            System.out.print(protocols.get(i).getProtocolName() + " ");

            if (device == null) {
                System.out.println("empty");
            } else {
                System.out.print("occupied " + device.getName() + " ");

                if ("Sensor".equals(device.getDevType())) {
                    System.out.print(sensors.get(device.getDevId()).getSensType() + " " + sensors.get(device.getDevId()).getDevType() + " " + sensors.get(device.getDevId()).getDevId() + " ");
                } else {
                    System.out.print(device.getDevType() + " " + device.getDevId() + " ");
                }

                System.out.println(device.getState());
            }
            i++;
        }
    }

    public void listDevices(String dev) {
        System.out.println("list of " + dev + "s:");

        if ("Sensor".equals(dev)) {
            Iterator<Sensor> sensorIterator = sensors.iterator();
            while (sensorIterator.hasNext()) {
                Sensor sensor = sensorIterator.next();

                System.out.println(sensor.getName() + " " + sensor.getDevId() + " " + sensor.getPortId() + " " + protocols.get(sensor.getPortId()).getProtocolName());
            }
        } else if ("Display".equals(dev)) {
            Iterator<Display> displayIterator = displays.iterator();

            while (displayIterator.hasNext()) {
                Display display = displayIterator.next();

                System.out.println(display.getName() + " " + display.getDevId() + " " + display.getPortId() + " " + protocols.get(display.getPortId()).getProtocolName());

            }
        } else if ("MotorDriver".equals(dev)) {
            Iterator<MotorDriver> motorDriverIterator = motorDrivers.iterator();

            while (motorDriverIterator.hasNext()) {
                MotorDriver motorDriver = motorDriverIterator.next();
                System.out.println(motorDriver.getName() + " " + motorDriver.getDevId() + " " + motorDriver.getPortId() + " " + protocols.get(motorDriver.getPortId()).getProtocolName());

            }
        } else if ("WirelessIO".equals(dev)) {
            Iterator<WirelessIO> wirelessIterator = wirelessIOs.iterator();

            while (wirelessIterator.hasNext()) {
                WirelessIO wireless = wirelessIterator.next();

                System.out.println(wireless.getName() + " " + wireless.getDevId() + " " + wireless.getPortId() + " " + protocols.get(wireless.getPortId()).getProtocolName());

            }
        }

    }

    public void turnOnDevice(int port) {
        // Port numarasının geçerli olup olmadığını kontrol et
        if (port >= 0 && port < devices.size()) {
            if (devices.get(port) == null) {
                System.err.println("This port is empty.");
                return;
            }
            devices.get(port).turnON(); // Cihazı aç
            protocols.get(port).write("turnON");
        } else {
            System.err.println("Invalid port number.");

        }
    }

    public void turnOffDevice(int port) {
        // Port numarasının geçerli olup olmadığını kontrol et
        if (port >= 0 && port < devices.size()) {
            if (devices.get(port) == null) {
                System.err.println("This port is empty.");
                return;
            }
            devices.get(port).turnOFF(); // Cihazı kapat
            protocols.get(port).write("turnOFF");

        } else {
            System.err.println("Invalid port number.");
        }
    }

    public void readSensor(int port) {
        if (port >= 0 && port < sensors.size()) {
            if (sensors.get(port) == null) {
                System.err.println("There is not device with this id.");
                return;
            }
            if (sensors.get(port).getState() == State.OFF) {
                System.err.println("Device is OFF. Cannot read data.");
                return;
            }
            System.out.println(sensors.get(port).getName() + " " + sensors.get(port).getSensType() + " " + sensors.get(port).getDevType() + ": " + sensors.get(port).data2String());
            protocols.get(sensors.get(port).getPortId()).read();

        } else {
            System.err.println("Invalid devId number or Device is OFF.");
        }

    }

    public void printData(int port, String data) {

        if (port >= 0 && port < displays.size()) {
            if (displays.get(port) == null) {
                System.err.println("There is not device with this id.");
                return;
            }
            if (displays.get(port).getState() == State.OFF) {
                System.err.println("Device is OFF. Cannot read data.");
                return;
            }
            displays.get(port).printData(data);
            protocols.get(displays.get(port).getPortId()).write(data);

        } else {
            System.err.println("Invalid devId number or Device is OFF.");
        }
    }

    public void changeMotorSpeed(int port, int speed) {

        if (port >= 0 && port < motorDrivers.size()) {
            if (motorDrivers.get(port) == null) {
                System.err.println("There is not device with this id.");
                return;
            }
            if (motorDrivers.get(port).getState() == State.OFF) {
                System.err.println("Device is OFF. Cannot read data.");
                return;
            }
            motorDrivers.get(port).setMotorSpeed(10);
            protocols.get(motorDrivers.get(port).getPortId()).write("" + speed + "");

        } else {
            System.err.println("Invalid devId number or Device is OFF.");
        }
    }

    public void sndData(int port, String data) {
        if (port >= 0 && port < wirelessIOs.size()) {
            if (wirelessIOs.get(port) == null) {
                System.err.println("There is not device with this id.");
                return;
            }
            if (wirelessIOs.get(port).getState() == State.OFF) {
                System.err.println("Device is OFF. Cannot read data.");
                return;
            }
            wirelessIOs.get(port).sendData(data);
            protocols.get(wirelessIOs.get(port).getPortId()).write(data);
        } else {
            System.err.println("Invalid devId number or Device is OFF.");
        }
    }

    public void revData(int port) {
        if (port >= 0 && port < wirelessIOs.size()) {
            if (wirelessIOs.get(port) == null) {
                System.err.println("There is not device with this id.");
                return;
            }
            if (wirelessIOs.get(port).getState() == State.OFF) {
                System.err.println("Device is OFF. Cannot read data.");
                return;
            }
            System.out.println(wirelessIOs.get(port).recvData());

            protocols.get(wirelessIOs.get(port).getPortId()).read();
        } else {
            System.err.println("Invalid devID number or Device is OFF.");
        }
    }

    public void exitting() {
        Iterator<Protocol> protocolIterator = protocols.iterator();
        while (protocolIterator.hasNext()) {
            Protocol protocol = protocolIterator.next();
            protocol.close();
        }
    }
}
