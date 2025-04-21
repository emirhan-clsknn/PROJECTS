package HWSystem.Devices;

import HWSystem.Protocols.I2C;
import HWSystem.Protocols.Protocol;

/**
 * Represents the MPU6050 IMU sensor that operates using the I2C protocol.
 */
public class MPU6050 extends IMUSensor {

    /**
     * Constructs an MPU6050 sensor with the specified protocol.
     *
     * @param protocol The communication protocol used by the sensor. Only I2C
     * protocol is supported.
     */
    public MPU6050(Protocol protocol) {
        if (!(protocol instanceof I2C)) {
            System.err.println("MPU6050 only supports I2C protocol.");
        } else {
            this.state = State.OFF;
            this.protocol = protocol;
        }
    }

    /**
     * Retrieves the name of the device.
     *
     * @return A string representing the name of the device, "MPU6050".
     */
    @Override
    public String getName() {
        return "MPU6050";
    }

    /**
     * Retrieves the acceleration value from the sensor.
     *
     * @return A float value representing the acceleration.
     */
    @Override
    public float getAccel() {
        return 1.00f;
    }

    /**
     * Turns the MPU6050 ON and updates its state.
     */
    @Override
    public void turnON() {
        System.out.println(this.getName() + ": Turning ON.");
        state = State.ON;
    }

    /**
     * Turns the MPU6050 OFF and updates its state.
     */
    @Override
    public void turnOFF() {
        System.out.println(this.getName() + ": Turning OFF.");
        state = State.OFF;
    }

    /**
     * Retrieves the rotational value from the sensor.
     *
     * @return A float value representing the rotation.
     */
    @Override
    public float getRot() {
        return 0.50f;
    }

    /**
     * Checks if a valid protocol is assigned to the MPU6050.
     *
     * @return True if a protocol is assigned, false otherwise.
     */
    @Override
    public boolean getProtocol() {
        return protocol != null;
    }

    /**
     * Retrieves the current state of the MPU6050 (ON/OFF).
     *
     * @return The current state of the device.
     */
    @Override
    public State getState() {
        return state;
    }
}
