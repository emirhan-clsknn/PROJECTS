
/**
 * Represents sensor data for a celestial body including temperature,
 * pressure, humidity, and radiation levels.
 */
public class SensorData {

    private double temperature;
    private double pressure;
    private double humidity;
    private double radiation;

    /**
     * Constructs a SensorData object with the specified sensor values.
     *
     * @param temperature the temperature in Kelvin
     * @param pressure the atmospheric pressure in Pascals
     * @param humidity the humidity percentage (0–100)
     * @param radiation the radiation level in Sieverts
     */
    public SensorData(double temperature, double pressure, double humidity, double radiation) {
        this.temperature = temperature;
        this.pressure = pressure;
        this.humidity = humidity;
        this.radiation = radiation;
    }

    /**
     * Gets the temperature value.
     *
     * @return the temperature in Kelvin
     */
    public double getTemperature() {
        return temperature;
    }

    /**
     * Gets the pressure value.
     *
     * @return the pressure in Pascals
     */
    public double getPressure() {
        return pressure;
    }

    /**
     * Gets the humidity value.
     *
     * @return the humidity percentage
     */
    public double getHumidity() {
        return humidity;
    }

    /**
     * Gets the radiation value.
     *
     * @return the radiation level in Sieverts
     */
    public double getRadiation() {
        return radiation;
    }
}
