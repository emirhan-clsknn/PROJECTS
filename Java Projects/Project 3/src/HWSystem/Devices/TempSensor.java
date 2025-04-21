package HWSystem.Devices;

/**
 * Abstract class representing a temperature sensor. Extends the Sensor class
 * and provides methods for retrieving the temperature.
 */
public abstract class TempSensor extends Sensor {

    /**
     * Returns the type of sensor.
     *
     * @return A string representing the sensor type, "TempSensor".
     */
    @Override
    public String getSensType() {
        return "TempSensor";
    }

    /**
     * Formats the temperature data into a string.
     *
     * @return A string representing the temperature, e.g. "Temp: 25.00C".
     */
    @Override
    public String data2String() {
        return String.format("Temp: %.2fC.", getTemp());
    }

    /**
     * Retrieves the current temperature from the sensor.
     *
     * @return A float representing the current temperature in Celsius.
     */
    public abstract float getTemp();
}
