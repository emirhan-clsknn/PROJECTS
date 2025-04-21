package HWSystem;

import HWSystem.Devices.*;
import HWSystem.Protocols.*;
import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class HWSystem {

    private ArrayList<Protocol> protocols;
    private ArrayList<Device> devices;
    private ArrayList<Device> motorDrivers;
    private ArrayList<Device> wirelessIOs;
    private ArrayList<Device> sensors;
    private ArrayList<Device> displays;
    private int numberOfMotors;
    private int numberOfWireless;
    private int numberOfSensors;
    private int numberOfDisplays;

    private int totalPort;

    public HWSystem() {
        protocols = new ArrayList<>(5);
        devices = new ArrayList<>(5);
        readConfig();
    }

    private void readConfig() {
        String filePath = "data.txt"; // Dosya adı
        ArrayList<String> protocolsClasses = new ArrayList<>();
        ArrayList<Integer> variables = new ArrayList<>();

        try (Scanner scanner = new Scanner(new File(filePath))) {
            // İlk satırı oku ve sınıfları belirle
            if (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(",");
                for (String part : parts) {
                    protocolsClasses.add(part.trim());
                }
            }

            // Diğer satırları oku ve integer listeye ekle
            while (scanner.hasNextInt()) {
                variables.add(scanner.nextInt());
            }
        } catch (Exception e) {
            e.printStackTrace();
            return;
        }

        this.numberOfSensors = variables.get(0);
        this.numberOfDisplays = variables.get(1);
        this.numberOfWireless = variables.get(2);
        this.numberOfMotors = variables.get(3);
        this.totalPort = this.numberOfDisplays + this.numberOfWireless + this.numberOfMotors + this.numberOfSensors;
        this.protocols = new ArrayList<>(this.totalPort);
        this.devices = new ArrayList<>(this.totalPort);
        this.sensors = new ArrayList<>(this.numberOfSensors);
        this.motorDrivers = new ArrayList<>(this.numberOfMotors);
        this.wirelessIOs = new ArrayList<>(this.numberOfWireless);
        this.displays = new ArrayList<>(this.numberOfDisplays);

        for (int i = 0; i < numberOfDisplays; i++) {
            displays.add(null);
        }
        for (int i = 0; i < numberOfMotors; i++) {
            motorDrivers.add(null);
        }
        for (int i = 0; i < numberOfWireless; i++) {
            wirelessIOs.add(null);
        }
        for (int i = 0; i < numberOfSensors; i++) {
            sensors.add(null);
        }

        for (int i = 0; i < protocolsClasses.size(); i++) {
            devices.add(null);
            switch (protocolsClasses.get(i)) {
                case "UART":
                    protocols.add(new UART());
                    break;
                case "SPI":
                    protocols.add(new SPI());
                    break;
                case "I2C":
                    protocols.add(new I2C());
                    break;
                case "OneWire":
                    protocols.add(new OneWire());
                    break;
            }
        }
    }

    public void addDevice(String dvname, int port, int id) {
        Device dvc;

        switch (dvname) {
            case "Bluetooth":
                dvc = new Bluetooth(protocols.get(port));
                break;
            case "BME280":
                dvc = new BME280(protocols.get(port));
                break;
            case "DHT11":
                dvc = new DHT11(protocols.get(port));
                break;
            case "GY951":
                dvc = new GY951(protocols.get(port));
                break;
            case "LCD":
                dvc = new LCD(protocols.get(port));
                break;
            case "OLED":
                dvc = new OLED(protocols.get(port));
                break;
            case "MPU6050":
                dvc = new MPU6050(protocols.get(port));
                break;
            case "PCA9685":
                dvc = new PCA9685(protocols.get(port));
                break;
            case "SparkFunMD":
                dvc = new SparkFunMD(protocols.get(port));
                break;
            case "Wifi":
                dvc = new Wifi(protocols.get(port));
                break;
            default:
                dvc = new Wifi(protocols.get(port));
                break;
        }

        if (port >= 0 && port < this.totalPort) {
            if (devices.get(port) == null && dvc.getProtocol() != false) {
                switch (dvc.getDevType()) {
                    case "WirelessIO":
                        if (this.numberOfWireless > 0) {
                            devices.set(port, dvc);
                            wirelessIOs.set(id, dvc);
                            --this.numberOfWireless;

                        } else {
                            System.out.println("No more WirelessIO available.");
                        }
                        break;

                    case "Sensor":
                        if (this.numberOfSensors > 0) {
                            devices.set(port, dvc);
                            sensors.set(id, dvc);
                            --this.numberOfSensors;
                        } else {
                            System.out.println("No more Sensor available.");
                        }
                        break;

                    case "Display":
                        if (this.numberOfDisplays > 0) {
                            devices.set(port, dvc);
                            while (id >= displays.size()) {
                                displays.add(null);
                            }
                            displays.set(id, dvc);
                            --this.numberOfDisplays;
                        } else {
                            System.out.println("No more Displays available.");
                        }
                        break;

                    case "MotorDriver":
                        if (this.numberOfMotors > 0) {
                            devices.set(port, dvc);
                            while (id >= motorDrivers.size()) {
                                motorDrivers.add(null);
                            }
                            motorDrivers.set(id, dvc);
                            --this.numberOfMotors;
                        } else {
                            System.out.println("No more motor drivers available.");
                        }
                        break;

                    default:
                        System.out.println("Invalid device type.");
                }
            } else {
                System.out.println("Port " + port + " is already occupied.");
            }
        } else {
            System.out.println("Invalid port number.");
        }
    }

    public void removeDevice(int port) {

        if (port >= 0 && port < this.totalPort) {
            if (devices.get(port) != null) {
                if (devices.get(port).getState() != State.OFF) {
                    System.out.println("Device is ON please turn off first.");
                    return;
                }
                Device dvc = devices.get(port);
                String devType = devices.get(port).getDevType();

                if (devType.equals("WirelessIO")) {
                    for (int i = 0; i < wirelessIOs.size(); i++) {
                        if (wirelessIOs.get(i) == dvc) {
                            wirelessIOs.set(i, null);
                            break;
                        }
                    }
                    devices.set(port, null);
                    this.numberOfWireless++;
                } else if (devType.equals("Sensor")) {
                    for (int i = 0; i < sensors.size(); i++) {
                        if (sensors.get(i) == dvc) {
                            sensors.set(i, null);
                            break;
                        }
                    }
                    devices.set(port, null);
                    this.numberOfSensors++;
                } else if (devType.equals("Display")) {
                    for (int i = 0; i < displays.size(); i++) {
                        if (displays.get(i) == dvc) {
                            displays.set(i, null);
                            break;
                        }
                    }
                    devices.set(port, null);
                    this.numberOfDisplays++;
                } else if (devType.equals("MotorDriver")) {
                    for (int i = 0; i < motorDrivers.size(); i++) {
                        if (motorDrivers.get(i) == dvc) {
                            motorDrivers.set(i, null);
                            break;
                        }
                    }
                    devices.set(port, null);
                    this.numberOfMotors++;
                } else {
                    System.out.println("Invalid device type.");
                }

            } else {
                System.out.println("This port is already empty.");
            }
        } else {
            System.out.println("Invalid port number.");
        }
    }

    public void listPorts() {
        System.out.println("List Of Ports:");
        for (int i = 0; i < protocols.size(); i++) {
            System.out.print(i + ". ");
            System.out.print(protocols.get(i).getProtocolName() + " ");
            if (devices.get(i) == null) {
                System.out.println("Empty");
            } else {
                System.out.print("occupied " + devices.get(i).getName() + " ");
                if ("Sensor".equals(devices.get(i).getDevType())) {
                    System.out.print(devices.get(i).getSensType() + " ");
                }
                System.err.print(devices.get(i).getDevType() + " ");
                switch (devices.get(i).getDevType()) {
                    case "WirelessIO":
                        for (int j = 0; j < wirelessIOs.size(); j++) {
                            if (devices.get(i) == wirelessIOs.get(j)) {
                                System.err.print(j + " ");
                            }
                        }
                        break;

                    case "Sensor":
                        for (int j = 0; j < sensors.size(); j++) {
                            if (devices.get(i) == sensors.get(j)) {
                                System.err.print(j + " ");
                            }
                        }
                        break;

                    case "Display":
                        for (int j = 0; j < displays.size(); j++) {
                            if (devices.get(i) == displays.get(j)) {
                                System.err.print(j + " ");
                            }
                        }
                        break;

                    case "MotorDriver":
                        for (int j = 0; j < motorDrivers.size(); j++) {
                            if (devices.get(i) == motorDrivers.get(j)) {
                                System.err.print(j + " ");
                            }
                        }
                        break;

                    default:
                        System.out.println("Invalid device type.");
                        break;

                }
                System.out.println(devices.get(i).getState());

            }
        }
    }

    public void listDevices(String dev) {
        System.out.println("List Of " + dev + ":");
        for (int i = 0; i < devices.size(); i++) {
            if (devices.get(i) != null && dev.equals(devices.get(i).getDevType())) {
                System.out.print(devices.get(i).getName() + " ");
                if (dev.equals("Sensor")) {
                    for (int k = 0; k < sensors.size(); k++) {
                        if (sensors.get(k) == devices.get(i)) {
                            System.out.print(k + " ");
                        }
                    }
                } else if (dev.equals("WirelessIO")) {
                    for (int k = 0; k < wirelessIOs.size(); k++) {
                        if (wirelessIOs.get(k) == devices.get(i)) {
                            System.out.print(k + " ");
                        }
                    }
                } else if (dev.equals("MotorDriver")) {
                    for (int k = 0; k < motorDrivers.size(); k++) {
                        if (motorDrivers.get(k) == devices.get(i)) {
                            System.out.print(k + " ");
                        }
                    }
                } else if (dev.equals("Display")) {
                    for (int k = 0; k < displays.size(); k++) {
                        if (displays.get(k) == devices.get(i)) {
                            System.out.print(k + " ");
                        }
                    }
                }
                System.err.print(i + " ");
                System.err.println(protocols.get(i).getProtocolName());
            }

        }

    }

    public void turnOnDevice(int port) {
        // Port numarasının geçerli olup olmadığını kontrol et
        if (port >= 0 && port < devices.size()) {
            devices.get(port).turnON(); // Cihazı aç
        } else {
            System.out.println("Invalid port number.");
        }
    }

    public void turnOffDevice(int port) {
        // Port numarasının geçerli olup olmadığını kontrol et
        if (port >= 0 && port < devices.size()) {
            devices.get(port).turnOFF(); // Cihazı kapat
        } else {
            System.out.println("Invalid port number.");
        }
    }

    public void readSensor(int port) {

        if (port >= 0 && port < sensors.size() && sensors.get(port).getState() == State.ON) {
            if ("Sensor".equals(sensors.get(port).getDevType())) {
                System.out.print(sensors.get(port).getName() + " ");
                if ("IMUSensor".equals(sensors.get(port).getSensType())) {

                    System.out.printf("%.2f ", sensors.get(port).getAccel());
                    System.out.print("Rot: ");
                    System.out.printf("%.2f\n", sensors.get(port).getRot());
                } else if ("TempSensor".equals(sensors.get(port).getSensType())) {
                    System.err.println("Temperature: " + sensors.get(port).getTemp());
                }
            } else {
                System.out.println("This port does not contain a sensor.");

            }
        } else {
            System.out.println("Invalid port number or Device is OFF.");
        }
    }

    public void printData(int port, String data) {

        if (port >= 0 && port < displays.size() && displays.get(port).getState() == State.ON) {
            if ("Display".equals(displays.get(port).getDevType())) {
                displays.get(port).printData(data);
            } else {
                System.out.println("This port does not contain a sensor.");
            }

        } else {
            System.out.println("Invalid port number or Device is OFF.");
        }
    }

    public void changeMotorSpeed(int port, int speed) {

        if (port >= 0 && port < motorDrivers.size() && motorDrivers.get(port).getState() == State.ON) {
            if ("MotorDriver".equals(motorDrivers.get(port).getDevType())) {

                System.out.print(motorDrivers.get(port).getName() + " ");
                motorDrivers.get(port).setMotorSpeed(10);
            } else {
                System.out.println("This port does not contain a sensor.");
            }

        } else {
            System.out.println("Invalid port number or Device is OFF.");
        }
    }

    public void sndData(int port, String data) {
        if (port >= 0 && port < wirelessIOs.size() && wirelessIOs.get(port).getState() == State.ON) {

            if ("WirelessIO".equals(wirelessIOs.get(port).getDevType())) {
                wirelessIOs.get(port).sendData(data);

            } else {
                System.out.println("This port does not contain a sensor.");
            }

        } else {
            System.out.println("Invalid port number or Device is OFF.");
        }
    }

    public void revData(int port) {
        if (port >= 0 && port < wirelessIOs.size() && wirelessIOs.get(port).getState() == State.ON) {

            if ("WirelessIO".equals(wirelessIOs.get(port).getDevType())) {
                System.err.print(wirelessIOs.get(port).getName() + " ");
                System.out.print(wirelessIOs.get(port).getDevType() + " :");
                System.out.println(wirelessIOs.get(port).recvData());
            } else {
                System.out.println("This port does not contain a sensor.");
            }

        } else {
            System.out.println("Invalid port number or Device is OFF.");
        }
    }
}
