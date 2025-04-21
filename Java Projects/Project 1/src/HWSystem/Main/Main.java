package Main;

import HWSystem.HWSystem;
import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HWSystem sys = new HWSystem();

        try {
            while (true) {
                System.out.println("Commands:");
                String command = scanner.nextLine().trim();

                if (command.isEmpty()) {
                    continue; // Boş satır kontrolü
                }
                String[] parts = command.split("\\s+");

                switch (parts[0]) {
                    case "turnON":
                        if (parts.length == 2) {
                            try {
                                sys.turnOnDevice(Integer.parseInt(parts[1]));
                            } catch (NumberFormatException e) {
                                System.out.println("Error: Invalid portID.");
                            }
                        } else {
                            System.out.println("Usage: turnON <portID>");
                        }
                        break;

                    case "turnOFF":
                        if (parts.length == 2) {
                            try {
                                sys.turnOffDevice(Integer.parseInt(parts[1]));
                            } catch (NumberFormatException e) {
                                System.out.println("Error: Invalid portID.");
                            }
                        } else {
                            System.out.println("Usage: turnOFF <portID>");
                        }
                        break;

                    case "addDev":
                        if (parts.length == 4) {
                            try {
                                sys.addDevice(parts[1], Integer.parseInt(parts[2]), Integer.parseInt(parts[3]));
                            } catch (NumberFormatException e) {
                                System.out.println("Error: Invalid portID or devID.");
                            }
                        } else {
                            System.out.println("Usage: addDev <devName> <portID> <devID>");
                        }
                        break;

                    case "rmDev":
                        if (parts.length == 2) {
                            try {
                                sys.removeDevice(Integer.parseInt(parts[1]));
                            } catch (NumberFormatException e) {
                                System.out.println("Error: Invalid portID.");
                            }
                        } else {
                            System.out.println("Usage: rmDev <portID>");
                        }
                        break;

                    case "list":
                        if (parts.length == 2) {
                            if ("ports".equals(parts[1])) {
                                sys.listPorts();
                            } else {
                                sys.listDevices(parts[1]);
                            }
                        } else {
                            System.out.println("Usage: list ports or list <devType>");
                        }
                        break;

                    case "readSensor":
                        sys.readSensor(Integer.parseInt(parts[1]));
                        break;
                    case "printDisplay":
                        if (parts.length == 3) {
                            try {
                                sys.printData(Integer.parseInt(parts[1]), parts[2]);
                            } catch (NumberFormatException e) {
                                System.out.println("Error: Invalid devID.");
                            }
                        } else {
                            System.out.println("Usage: printDisplay <devID> <String>");
                        }
                        break;

                    case "readWireless":
                        sys.revData(Integer.parseInt(parts[1]));
                        break;
                    case "writeWireless":
                        sys.sndData(Integer.parseInt(parts[1]), parts[2]);
                        break;
                    case "setMotorSpeed":
                        sys.changeMotorSpeed(Integer.parseInt(parts[1]), Integer.parseInt(parts[2]));
                        break;

                    case "exit":
                        System.out.println("Exiting...");
                        return;

                    default:
                        System.out.println("Invalid command!");
                }
            }
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

}
