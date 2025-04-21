package HWSystem.Devices;

/**
 * Represents a general sensor device. This class serves as a base class for
 * specific types of sensors.
 */
public abstract class Sensor extends Device {

    /**
     * Retrieves the type of the device, which is "Sensor".
     *
     * @return A string representing the device type, "Sensor".
     */
    @Override
    public String getDevType() {
        return "Sensor";
    }

    /**
     * Retrieves the type of the sensor (e.g., IMU, temperature sensor, etc.).
     *
     * @return A string representing the sensor type.
     */
    public abstract String getSensType();

    /**
     * Converts the sensor's data into a string representation.
     *
     * @return A string containing the sensor's data in a human-readable format.
     */
    public abstract String data2String();
}
