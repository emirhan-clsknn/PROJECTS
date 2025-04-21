package HWSystem.Devices;

/**
 * Represents an abstract motor driver device.
 */
public abstract class MotorDriver extends Device {

    /**
     * Retrieves the type of the device.
     *
     * @return A string representing the device type, "MotorDriver".
     */
    @Override
    public String getDevType() {
        return "MotorDriver";
    }

    /**
     * Turns off the motor driver.
     */
    @Override
    public abstract void turnOFF();

    /**
     * Turns on the motor driver.
     */
    @Override
    public abstract void turnON();

    /**
     * Retrieves the name of the motor driver.
     *
     * @return A string representing the name of the device.
     */
    @Override
    public abstract String getName();

    /**
     * Retrieves the current state of the motor driver.
     *
     * @return The current state of the device.
     */
    @Override
    public abstract State getState();

    /**
     * Sets the speed of the motor.
     *
     * @param speed The speed value to set for the motor.
     */
    public abstract void setMotorSpeed(int speed);
}
