package HWSystem.Devices;

import HWSystem.Protocols.Protocol;

/**
 * Represents a generic device in the system. This is an abstract class that
 * defines the common properties and behaviors of all devices.
 */
public abstract class Device {

    /**
     * The communication protocol used by the device.
     */
    protected Protocol protocol;

    /**
     * The port ID where the device is connected.
     */
    protected int portId;

    /**
     * The unique device ID.
     */
    protected int devId;

    /**
     * The current state of the device (ON or OFF).
     */
    protected State state = State.OFF;

    /**
     * Retrieves the port ID of the device.
     *
     * @return The port ID.
     */
    public int getPortId() {
        return portId;
    }

    /**
     * Retrieves the device ID.
     *
     * @return The device ID.
     */
    public int getDevId() {
        return devId;
    }

    /**
     * Sets the device ID.
     *
     * @param devId The new device ID.
     */
    public void setDevId(int devId) {
        this.devId = devId;
    }

    /**
     * Sets the port ID where the device is connected.
     *
     * @param portId The new port ID.
     */
    public void setPortId(int portId) {
        this.portId = portId;
    }

    /**
     * Checks if the device has a valid protocol.
     *
     * @return true if a protocol is set, false otherwise.
     */
    public abstract boolean getProtocol();

    /**
     * Retrieves the name of the device.
     *
     * @return The device name.
     */
    public abstract String getName();

    /**
     * Turns off the device.
     */
    public abstract void turnOFF();

    /**
     * Turns on the device.
     */
    public abstract void turnON();

    /**
     * Retrieves the current state of the device.
     *
     * @return The current state (ON or OFF).
     */
    public abstract State getState();

    /**
     * Retrieves the type of the device.
     *
     * @return The device type.
     */
    public abstract String getDevType();

}
