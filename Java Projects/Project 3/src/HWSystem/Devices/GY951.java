package HWSystem.Devices;

import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.SPI;
import HWSystem.Protocols.UART;

/**
 * Represents the GY-951 IMU sensor. This sensor supports SPI and UART
 * communication protocols.
 */
public class GY951 extends IMUSensor {

    /**
     * Constructs a GY-951 sensor with the specified protocol.
     *
     * @param protocol The communication protocol used by the sensor. Must be an
     * instance of SPI or UART.
     */
    public GY951(Protocol protocol) {
        if (!(protocol instanceof SPI || protocol instanceof UART)) {
            System.err.println("GY-951 is only compatible with SPI and UART protocols.");
        } else {
            this.state = State.OFF;
            this.protocol = protocol;
        }
    }

    /**
     * Retrieves the name of the sensor.
     *
     * @return The sensor name "GY_951".
     */
    @Override
    public String getName() {
        return "GY_951";
    }

    /**
     * Retrieves the acceleration value.
     *
     * @return The acceleration value as a float.
     */
    @Override
    public float getAccel() {
        return 1.0f;
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
     * Retrieves the rotation value.
     *
     * @return The rotation value as a float.
     */
    @Override
    public float getRot() {
        return 0.50f;
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
     * Checks if the sensor has a valid protocol.
     *
     * @return true if a valid protocol is set, false otherwise.
     */
    @Override
    public boolean getProtocol() {
        return protocol != null;
    }
}
