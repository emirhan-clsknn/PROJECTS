
import java.util.*;

/**
 * The {@code PlanetarySystem} class represents a hierarchical structure of
 * celestial bodies including a central star, planets, and their satellites
 * (moons). It stores environmental sensor data for each node and provides
 * methods to add planets/satellites, analyze radiation anomalies, retrieve
 * paths, and print reports.
 */
public class PlanetarySystem {

    Node root; // Yıldız (Sun) kök node

    /**
     * Constructs a planetary system with a single star node as the root.
     *
     * @param starName the name of the star
     * @param temperature temperature of the star in Kelvin
     * @param pressure pressure of the star in Pascals (must be non-negative)
     * @param humidity must be 0 for a star
     * @param radiation radiation level in Sieverts (must be non-negative)
     */
    public PlanetarySystem(String starName, double temperature, double pressure, double humidity, double radiation) {
        if (pressure < 0) {
            System.err.println("Error: Pressure cannot be negative.");
            return;
        }
        if (humidity != 0) {
            System.err.println("Error: Humidity must be 0 for a star.");
            return;
        }
        if (radiation < 0) {
            System.err.println("Error: Radiation cannot be negative.");
            return;
        }
        if (starName == null || starName.isEmpty()) {
            System.err.println("Error: Star name cannot be null or empty.");
            return;
        }

        SensorData starData = new SensorData(temperature, pressure, 0, radiation); // Yıldızda nem yok
        this.root = new Node(starName, "Star", starData);
        System.out.println("Planetary system '" + starName + "' created successfully.");
    }

    /**
     * Adds a planet to the specified parent node in the system.
     *
     * @param planetName name of the planet
     * @param parentName name of the parent node (must be a star or planet)
     * @param temperature temperature of the planet
     * @param pressure pressure of the planet (non-negative)
     * @param humidity humidity of the planet (0-100)
     * @param radiation radiation level of the planet (non-negative)
     */
    public void addPlanet(String planetName, String parentName, double temperature, double pressure, double humidity, double radiation) {
        if (planetName == null || planetName.isEmpty()) {
            System.err.println("Error: Planet name cannot be null or empty.");
            return;
        }
        if (pressure < 0) {
            System.err.println("Error: Pressure cannot be negative.");
            return;
        }
        if (humidity < 0 || humidity > 100) {
            System.err.println("Error: Humidity must be between 0 and 100.");
            return;
        }
        if (radiation < 0) {
            System.err.println("Error: Radiation cannot be negative.");
            return;
        }

        SensorData planetData = new SensorData(temperature, pressure, humidity, radiation);
        Node planet = new Node(planetName, "Planet", planetData);
        Node parentNode = findNode(parentName, root);
        if (parentNode != null) {
            if (parentNode.getType() == "Star") {
                if (parentNode.getChildren().size() > 0) {
                    System.err.println("Error: Parent node (" + parentName + ") you can not add 1 more planet this node.");
                    return;
                } else {
                    parentNode.addChild(planet);
                    System.out.println("Planet '" + planetName + "' added to '" + parentName + "'.");
                }
            } else if (parentNode.getType().equals("Planet")) {
                for (Node child : parentNode.getChildren()) {
                    if (child.getType().equals("Planet")) {
                        System.err.println("Error: You can not add 1 more planet to this node.");
                        return;
                    }
                }
                parentNode.addChild(planet);
                System.out.println("Planet '" + planetName + "' added to '" + parentName + "'.");
            } else {
                System.err.println("Error: Parent node (" + parentName + ") is not a valid planet or star.");
                return;
            }

        } else {
            System.err.println("Error: Parent node (" + parentName + ") not found.");
        }
    }

    /**
     * Adds a satellite (moon) to a planet node.
     *
     * @param satelliteName name of the satellite
     * @param parentName name of the parent planet
     * @param temperature temperature of the satellite
     * @param pressure pressure of the satellite (non-negative)
     * @param humidity humidity of the satellite (0-100)
     * @param radiation radiation level of the satellite (non-negative)
     */
    public void addSatellite(String satelliteName, String parentName, double temperature, double pressure, double humidity, double radiation) {
        if (satelliteName == null || satelliteName.isEmpty()) {
            System.err.println("Error: Satellite name cannot be null or empty.");
            return;
        }
        if (pressure < 0) {
            System.err.println("Error: Pressure cannot be negative.");
            return;
        }
        if (humidity < 0 || humidity > 100) {
            System.err.println("Error: Humidity must be between 0 and 100.");
            return;
        }
        if (radiation < 0) {
            System.err.println("Error: Radiation cannot be negative.");
            return;
        }

        SensorData satelliteData = new SensorData(temperature, pressure, humidity, radiation);
        Node satellite = new Node(satelliteName, "Moon", satelliteData);
        Node parentNode = findNode(parentName, root);

        if (parentNode != null) {
            if (parentNode.getType().equals("Star") || parentNode.getType().equals("Moon")) {
                System.err.println("Error: You cannot add a satellite to a star and moon.");
                return;
            }
            parentNode.addChild(satellite);
            System.out.println("Satellite '" + satelliteName + "' added to '" + parentName + "'.");
        } else {
            System.err.println("Error: Parent node (" + parentName + ") not found.");
        }
    }

    /**
     * Recursively searches for a node with the specified name.
     *
     * @param nodeName the name of the node to find
     * @param currentNode the current node being searched
     * @return the found node or {@code null} if not found
     */
    private Node findNode(String nodeName, Node currentNode) {
        if (currentNode == null || nodeName == null || nodeName.isEmpty()) {
            return null;
        }

        Queue<Node> queue = new LinkedList<>();
        queue.add(currentNode);

        while (!queue.isEmpty()) {
            Node node = queue.poll();
            if (node.getName().equals(nodeName)) {
                return node;
            }
            queue.addAll(node.getChildren());
        }

        return null;
    }

    /**
     * Finds all nodes in the planetary system with radiation greater than the
     * given threshold.
     *
     * @param threshold the radiation threshold (must be non-negative)
     * @return a list of nodes with high radiation
     */
    public List<Node> findRadiationAnomalies(double threshold) {
        if (threshold < 0) {
            System.err.println("Error: Radiation threshold cannot be negative.");
            return Collections.emptyList();
        }
        if (root == null) {
            return Collections.emptyList();
        }
        List<Node> anomalies = new ArrayList<>();
        findRadiationAnomaliesRecursive(root, threshold, anomalies);
        return anomalies;
    }

    /**
     * Helper method for recursively identifying radiation anomalies.
     *
     * @param currentNode current node being checked
     * @param threshold radiation threshold
     * @param anomalies list to store anomalous nodes
     */
    private void findRadiationAnomaliesRecursive(Node currentNode, double threshold, List<Node> anomalies) {
        if (currentNode.getSensorData().getRadiation() > threshold) {
            anomalies.add(currentNode);
        }
        for (Node child : currentNode.getChildren()) {
            findRadiationAnomaliesRecursive(child, threshold, anomalies);
        }
    }

    /**
     * Retrieves the path to the specified planet as a stack of node names.
     *
     * @param planetName the name of the target node
     * @return a stack representing the path from the root to the target node
     */
    public Stack<String> getPathTo(String planetName) {
        if (planetName == null || planetName.isEmpty()) {
            System.err.println("Error: Planet name cannot be null or empty.");
            return new Stack<>();
        }
        Stack<String> path = new Stack<>();
        boolean found = getPathToRecursive(root, planetName, path);
        if (!found) {
            System.err.println("Error: Planet " + planetName + " not found.");
        }
        return path;
    }

    /**
     * Helper method for recursively building the path to a node.
     *
     * @param currentNode the current node
     * @param planetName the name of the destination node
     * @param path the path stack being built
     * @return {@code true} if the node was found, otherwise {@code false}
     */
    private boolean getPathToRecursive(Node currentNode, String planetName, Stack<String> path) {
        if (currentNode == null) {
            return false;
        }
        path.push(currentNode.getName());
        if (currentNode.getName().equals(planetName)) {
            return true;
        }
        for (Node child : currentNode.getChildren()) {
            if (getPathToRecursive(child, planetName, path)) {
                return true;
            }
        }
        path.pop(); // Backtrack
        return false;
    }

    /**
     * Prints a detailed mission report for all nodes in the system.
     */
    public void printMissionReport() {
        printMissionReportRecursive(root);
    }

    /**
     * Helper method for recursively printing the mission report.
     *
     * @param currentNode the node being reported
     */
    private void printMissionReportRecursive(Node currentNode) {
        if (currentNode == null) {
            return;
        }

        System.out.println(currentNode.getType() + ": " + getPathTo(currentNode.getName()) + " " + currentNode.getName());
        SensorData data = currentNode.getSensorData();
        System.out.println("  Temperature: " + data.getTemperature() + " Kelvin");
        System.out.println("  Pressure: " + data.getPressure() + " Pascals");
        System.out.println("  Humidity: " + data.getHumidity() + " %");
        System.out.println("  Radiation: " + data.getRadiation() + " Sieverts");

        for (Node child : currentNode.getChildren()) {
            printMissionReportRecursive(child);
        }
    }

    /**
     * Prints a mission report for a specific node.
     *
     * @param nodeName the name of the node
     */
    public void printMissionReport(String nodeName) {
        Node node = findNode(nodeName, root); // artık derinlikli arama yapıyoruz

        if (node != null) {
            System.out.println(node.getType() + ": " + getPathTo(nodeName) + " " + node.getName());
            System.out.println("  Temperature: " + node.getSensorData().getTemperature() + " Kelvin");
            System.out.println("  Pressure: " + node.getSensorData().getPressure() + " Pascals");
            System.out.println("  Humidity: " + node.getSensorData().getHumidity() + " %");
            System.out.println("  Radiation: " + node.getSensorData().getRadiation() + " Sieverts");
        } else {
            System.err.println("Error: Node " + nodeName + " not found.");
        }
    }

}
