
import java.util.*;

/**
 * Represents a node in the planetary system hierarchy. A node can be of type
 * Star, Planet, or Moon, and may contain child nodes.
 */
public class Node {

    private String name;
    private String type; // Possible values: "Planet", "Moon", "Star"
    private SensorData sensorData;
    private List<Node> children;

    /**
     * Constructs a Node with a given name, type, and sensor data.
     *
     * @param name the name of the celestial body
     * @param type the type of the celestial body ("Star", "Planet", or "Moon")
     * @param sensorData the sensor data associated with this node
     */
    public Node(String name, String type, SensorData sensorData) {
        this.name = name;
        this.type = type;
        this.sensorData = sensorData;
        this.children = new ArrayList<>();
    }

    /**
     * Adds a child node to this node.
     *
     * @param child the child node to add
     */
    public void addChild(Node child) {
        this.children.add(child);
    }

    /**
     * Gets the name of this node.
     *
     * @return the name of the celestial body
     */
    public String getName() {
        return name;
    }

    /**
     * Gets the type of this node.
     *
     * @return the type of the celestial body ("Star", "Planet", or "Moon")
     */
    public String getType() {
        return type;
    }

    /**
     * Gets the sensor data associated with this node.
     *
     * @return the sensor data of the node
     */
    public SensorData getSensorData() {
        return sensorData;
    }

    /**
     * Gets the list of child nodes of this node.
     *
     * @return a list of children (e.g. planets or moons)
     */
    public List<Node> getChildren() {
        return children;
    }
}
