package HWSystem.Devices;

import HWSystem.Protocols.I2C;
import HWSystem.Protocols.Protocol;

/**
 * Represents the PCA9685 motor driver that operates using the I2C protocol.
 */
public class PCA9685 extends MotorDriver {

    /**
     * Constructs a PCA9685 motor driver with the specified protocol.
     *
     * @param protocol The communication protocol used by the motor driver. Only
     * I2C protocol is supported.
     */
    public PCA9685(Protocol protocol) {
        if (!(protocol instanceof I2C)) {
            System.err.println("PCA9685 supports only I2C.");
        } else {
            this.protocol = protocol;
            state = State.OFF;
        }
    }

    /**
     * Retrieves the name of the motor driver.
     *
     * @return A string representing the name of the motor driver, "PCA9685".
     */
    @Override
    public String getName() {
        return "PCA9685";
    }

    /**
     * Sets the speed of the motor.
     *
     * @param speed The speed to set for the motor. A value representing motor
     * speed.
     */
    @Override
    public void setMotorSpeed(int speed) {
        if (protocol != null) {
            System.out.println(this.getName() + ": Setting speed to " + speed + ".");
        } else {
            System.err.println("Protocol is missing for " + getName());
        }
    }

    /**
     * Turns the motor driver ON and updates its state.
     */
    @Override
    public void turnON() {
        System.out.println(this.getName() + ": Turning ON.");
        state = State.ON;
    }

    /**
     * Turns the motor driver OFF and updates its state.
     */
    @Override
    public void turnOFF() {
        System.out.println(this.getName() + ": Turning OFF.");
        state = State.OFF;
    }

    /**
     * Retrieves the current state of the motor driver (ON/OFF).
     *
     * @return The current state of the motor driver.
     */
    @Override
    public State getState() {
        return state;
    }

    /**
     * Checks if a valid protocol is assigned to the motor driver.
     *
     * @return True if a protocol is assigned, false otherwise.
     */
    @Override
    public boolean getProtocol() {
        return protocol != null;
    }
}
