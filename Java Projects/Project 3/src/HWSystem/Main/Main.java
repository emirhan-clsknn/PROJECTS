package Main;

import HWSystem.HWSystem;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);

    /**
     * The main entry point for the application. It reads commands from the user
     * and executes them on the HWSystem.
     *
     * @param args Command-line arguments (not used in this version).
     */
    public static void main(String[] args) {
        HWSystem sys = new HWSystem();

        // Read configuration from the provided file paths
        sys.readConfig(args[0], args[1]);

        // Create a queue to store commands entered by the user
        Queue<String> commandQueue = new LinkedList<>();

        try {
            // Infinite loop to read user commands until 'exit' is entered
            while (true) {
                String command = scanner.nextLine().trim();

                // Skip empty lines
                if (command.isEmpty()) {
                    continue;
                }

                // Exit command
                if (command.equals("exit")) {
                    break;
                }

                // Add the command to the queue
                commandQueue.add(command);
            }

            // Execute all commands in the queue
            Iterator<String> iterator = commandQueue.iterator();
            while (iterator.hasNext()) {
                String command = iterator.next();
                String[] parts = command.split("\\s+");

                // Process each command type
                switch (parts[0]) {
                    case "turnON":
                        if (parts.length == 2) {
                            try {
                                sys.turnOnDevice(Integer.parseInt(parts[1]));
                            } catch (NumberFormatException e) {
                                System.err.println("Error: Invalid portID.");
                            }
                        } else {
                            System.err.println("Usage: turnON <portID>");
                        }
                        break;

                    case "turnOFF":
                        if (parts.length == 2) {
                            try {
                                sys.turnOffDevice(Integer.parseInt(parts[1]));
                            } catch (NumberFormatException e) {
                                System.err.println("Error: Invalid portID.");
                            }
                        } else {
                            System.err.println("Usage: turnOFF <portID>");
                        }
                        break;

                    case "addDev":
                        if (parts.length == 4) {
                            try {
                                sys.addDevice(parts[1], Integer.parseInt(parts[2]), Integer.parseInt(parts[3]));
                            } catch (NumberFormatException e) {
                                System.err.println("Error: Invalid portID or devID.");
                            }
                        } else {
                            System.err.println("Usage: addDev <devName> <portID> <devID>");
                        }
                        break;

                    case "rmDev":
                        if (parts.length == 2) {
                            try {
                                sys.removeDevice(Integer.parseInt(parts[1]));
                            } catch (NumberFormatException e) {
                                System.err.println("Error: Invalid portID.");
                            }
                        } else {
                            System.err.println("Usage: rmDev <portID>");
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
                            System.err.println("Usage: list ports or list <devType>");
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
                                System.err.println("Error: Invalid devID.");
                            }
                        } else {
                            System.err.println("Usage: printDisplay <devID> <String>");
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

                    default:
                        System.err.println("Invalid command!");
                }
            }

            // Exiting the application
            System.out.println("Exiting ...");
            sys.exitting();
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}
