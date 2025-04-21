
import java.util.*;

/**
 * Main class for interacting with the Planetary System simulation.
 * <p>
 * Accepts user commands from the console to create planetary systems, add
 * planets or satellites, search for radiation anomalies, find paths to specific
 * nodes, and print mission reports.
 */
public class Main {

    /**
     * Entry point of the program. Continuously listens for user commands and
     * delegates actions to the PlanetarySystem object.
     *
     * Supported commands:
     * <ul>
     * <li><code>create planetSystem &lt;starName&gt; &lt;temp&gt; &lt;pres&gt; &lt;hum&gt; &lt;rad&gt;</code></li>
     * <li><code>addPlanet &lt;planetName&gt; &lt;parentName&gt; &lt;temp&gt; &lt;pres&gt; &lt;hum&gt; &lt;rad&gt;</code></li>
     * <li><code>addSatellite &lt;satelliteName&gt; &lt;parentName&gt; &lt;temp&gt; &lt;pres&gt; &lt;hum&gt; &lt;rad&gt;</code></li>
     * <li><code>findRadiationAnomalies &lt;threshold&gt;</code></li>
     * <li><code>getPathTo &lt;nodeName&gt;</code></li>
     * <li><code>printMissionReport</code> or
     * <code>printMissionReport &lt;nodeName&gt;</code></li>
     * <li><code>exit</code> to quit the program</li>
     * </ul>
     *
     * @param args not used
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PlanetarySystem system = null;

        while (true) {
            String command = scanner.nextLine().trim();

            try {
                if (command.startsWith("create planetSystem")) {
                    String[] parts = command.split(" ");
                    String starName = parts[2];
                    double temperature = Double.parseDouble(parts[3]);
                    double pressure = Double.parseDouble(parts[4]);
                    double humidity = Double.parseDouble(parts[5]);
                    double radiation = Double.parseDouble(parts[6]);
                    if (humidity != 0) {
                        System.err.println("Error: Humidity must be zero.");
                        continue;
                    }
                    system = new PlanetarySystem(starName, temperature, pressure, humidity, radiation);

                } else if (command.startsWith("addPlanet")) {
                    String[] parts = command.split(" ");
                    String planetName = parts[1];
                    String parentName = parts[2];
                    double temperature = Double.parseDouble(parts[3]);
                    double pressure = Double.parseDouble(parts[4]);
                    double humidity = Double.parseDouble(parts[5]);
                    double radiation = Double.parseDouble(parts[6]);

                    if (system != null) {
                        system.addPlanet(planetName, parentName, temperature, pressure, humidity, radiation);

                    } else {
                        System.err.println("Error: No planetary system exists. Please create one first.");
                    }

                } else if (command.startsWith("addSatellite")) {
                    String[] parts = command.split(" ");
                    String satelliteName = parts[1];
                    String parentName = parts[2];
                    double temperature = Double.parseDouble(parts[3]);
                    double pressure = Double.parseDouble(parts[4]);
                    double humidity = Double.parseDouble(parts[5]);
                    double radiation = Double.parseDouble(parts[6]);

                    if (system != null) {
                        system.addSatellite(satelliteName, parentName, temperature, pressure, humidity, radiation);

                    } else {
                        System.err.println("Error: No planetary system exists. Please create one first.");
                    }

                } else if (command.startsWith("findRadiationAnomalies")) {
                    String[] parts = command.split(" ");
                    double threshold = Double.parseDouble(parts[1]);
                    if (system != null) {
                        List<Node> anomalies = system.findRadiationAnomalies(threshold);
                        if (anomalies.isEmpty()) {
                            System.err.println("No anomalies found.");
                        } else {
                            System.err.println("Radiation anomalies above threshold " + threshold + ":");
                            for (Node anomaly : anomalies) {
                                System.err.println("Anomaly found in: " + anomaly.getName());
                            }
                        }
                    } else {
                        System.err.println("Error: No planetary system exists. Please create one first.");
                    }

                } else if (command.startsWith("getPathTo")) {
                    String[] parts = command.split(" ");
                    String planetName = parts[1];
                    if (system != null) {
                        Stack<String> path = system.getPathTo(planetName);
                        if (!path.isEmpty()) {
                            System.err.println("Path to " + planetName + ": " + path);
                        }
                    } else {
                        System.err.println("Error: No planetary system exists. Please create one first.");
                    }

                } else if (command.startsWith("printMissionReport")) {
                    if (command.split(" ").length == 1) {
                        if (system != null) {
                            system.printMissionReport();
                        } else {
                            System.err.println("Error: No planetary system exists. Please create one first.");
                        }
                    } else {
                        String[] parts = command.split(" ");
                        String nodeName = parts[1];
                        if (system != null) {
                            system.printMissionReport(nodeName);
                        } else {
                            System.err.println("Error: No planetary system exists. Please create one first.");
                        }
                    }

                } else if (command.equals("exit")) {
                    System.err.println("Exiting the program.");
                    break;

                } else {
                    System.err.println("Invalid command. Please try again.");
                }

            } catch (Exception e) {
                System.err.println("An error occurred while processing the command: " + e.getMessage());
            }
        }
    }
}
