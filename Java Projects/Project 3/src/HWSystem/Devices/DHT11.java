package HWSystem.Devices;

import HWSystem.Protocols.OneWire;
import HWSystem.Protocols.Protocol;

/**
 * Represents a DHT11 temperature and humidity sensor. This sensor operates
 * using the OneWire protocol.
 */
public class DHT11 extends TempSensor {

    /**
     * Constructs a DHT11 sensor with the specified protocol.
     *
     * @param protocol The communication protocol used by the sensor. Must be an
     * instance of OneWire.
     */
    public DHT11(Protocol protocol) {
        if (protocol instanceof OneWire) {
            this.state = State.OFF;
            this.protocol = protocol;
        } else {
            System.err.println("DHT11 only supports OneWire protocol.");
            this.protocol = null;
            this.state = State.OFF;
        }
    }

    /**
     * Retrieves the name of the sensor.
     *
     * @return The sensor name "DHT11".
     */
    @Override
    public String getName() {
        return "DHT11";
    }

    /**
     * Turns on the sensor.
     */
    @Override
    public void turnON() {
        System.out.println(this.getName() + ": Turning ON.");
        state = State.ON;
    }

    /**
     * Turns off the sensor.
     */
    @Override
    public void turnOFF() {
        System.out.println(this.getName() + ": Turning OFF.");
        state = State.OFF;
    }

    /**
     * Checks if the sensor has a valid protocol.
     *
     * @return true if a valid protocol is set, false otherwise.
     */
    @Override
    public boolean getProtocol() {
        return protocol != null;
    }

    /**
     * Retrieves the current state of the sensor.
     *
     * @return The current state (ON or OFF).
     */
    @Override
    public State getState() {
        return state;
    }

    /**
     * Retrieves the current temperature reading from the sensor.
     *
     * @return The temperature value in degrees Celsius.
     */
    @Override
    public float getTemp() {
        return 24.00f;
    }
}
