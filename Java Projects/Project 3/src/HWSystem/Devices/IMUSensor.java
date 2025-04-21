package HWSystem.Devices;

/**
 * Represents an Inertial Measurement Unit (IMU) sensor. This is an abstract
 * class that provides common functionality for all IMU sensors.
 */
public abstract class IMUSensor extends Sensor {

    /**
     * Retrieves the type of the sensor.
     *
     * @return A string representing the sensor type, "IMUSensor".
     */
    @Override
    public String getSensType() {
        return "IMUSensor";
    }

    /**
     * Converts the sensor data to a string representation.
     *
     * @return A formatted string containing acceleration and rotation values.
     */
    @Override
    public String data2String() {
        return String.format("Accel: %.2f, Rot: %.2f.", getAccel(), getRot());
    }

    /**
     * Retrieves the acceleration value measured by the sensor.
     *
     * @return The acceleration value as a float.
     */
    public abstract float getAccel();

    /**
     * Retrieves the rotational value measured by the sensor.
     *
     * @return The rotation value as a float.
     */
    public abstract float getRot();
}
