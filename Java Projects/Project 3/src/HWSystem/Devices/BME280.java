package HWSystem.Devices;

import HWSystem.Protocols.I2C;
import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.SPI;

/**
 * Represents a BME280 temperature sensor. This sensor supports communication
 * via I2C and SPI protocols.
 */
public class BME280 extends TempSensor {

    /**
     * Constructs a BME280 sensor with the specified protocol. If the protocol
     * is not I2C or SPI, a warning is displayed.
     *
     * @param protocol The communication protocol to be used.
     */
    public BME280(Protocol protocol) {
        if (protocol instanceof I2C || protocol instanceof SPI) {
            this.state = State.OFF;
            this.protocol = protocol;
        } else {
            System.err.println("BME280 supports only I2C and SPI.");
            this.protocol = null;
            this.state = State.OFF;
        }
    }

    /**
     * Retrieves the name of the sensor.
     *
     * @return The name "BME280".
     */
    @Override
    public String getName() {
        return "BME280";
    }

    /**
     * Checks if the BME280 sensor has a valid protocol.
     *
     * @return true if a protocol is set, false otherwise.
     */
    @Override
    public boolean getProtocol() {
        return protocol != null;
    }

    /**
     * Retrieves the current temperature reading from the sensor.
     *
     * @return The temperature value in Celsius.
     */
    @Override
    public float getTemp() {
        return 24.0f;
    }

    /**
     * Turns on the BME280 sensor.
     */
    @Override
    public void turnON() {
        System.out.println(this.getName() + ": Turning ON.");
        state = State.ON;
    }

    /**
     * Turns off the BME280 sensor.
     */
    @Override
    public void turnOFF() {
        System.out.println(this.getName() + ": Turning OFF.");
        state = State.OFF;
    }

    /**
     * Retrieves the current state of the BME280 sensor.
     *
     * @return The current state (ON or OFF).
     */
    @Override
    public State getState() {
        return state;
    }
}
