package HWSystem.Devices;

import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.SPI;

/**
 * Represents the SparkFunMD motor driver that operates using the SPI protocol.
 */
public class SparkFunMD extends MotorDriver {

    /**
     * Constructs a SparkFunMD motor driver with the specified protocol.
     *
     * @param protocol The communication protocol used by the motor driver. Only
     * SPI protocol is supported.
     */
    public SparkFunMD(Protocol protocol) {
        if (!(protocol instanceof SPI)) {
            System.err.println("SparkFunMD supports only SPI.");
        } else {
            this.protocol = protocol;
            state = State.OFF;
        }
    }

    /**
     * Turns the SparkFunMD motor driver ON and updates its state.
     */
    @Override
    public void turnON() {
        System.out.println(this.getName() + ": Turning ON.");
        state = State.ON;
    }

    /**
     * Turns the SparkFunMD motor driver OFF and updates its state.
     */
    @Override
    public void turnOFF() {
        System.out.println(this.getName() + ": Turning OFF.");
        state = State.OFF;
    }

    /**
     * Checks if a valid protocol is assigned to the SparkFunMD motor driver.
     *
     * @return True if a protocol is assigned, false otherwise.
     */
    @Override
    public boolean getProtocol() {
        return protocol != null;
    }

    /**
     * Retrieves the name of the motor driver.
     *
     * @return A string representing the name of the device, "SparkFunMD".
     */
    @Override
    public String getName() {
        return "SparkFunMD";
    }

    /**
     * Retrieves the current state of the motor driver (ON/OFF).
     *
     * @return The current state of the device.
     */
    @Override
    public State getState() {
        return state;
    }

    /**
     * Sets the motor speed for the SparkFunMD motor driver.
     *
     * @param speed The speed to set the motor to.
     */
    @Override
    public void setMotorSpeed(int speed) {
        if (protocol != null) {
            System.out.println(this.getName() + ": Setting speed to " + speed + ".");
        } else {
            System.err.println("Protocol is missing for " + getName());
        }
    }
}
