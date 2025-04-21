package HWSystem.Devices;

import HWSystem.Protocols.I2C;
import HWSystem.Protocols.Protocol;

/**
 * Represents an LCD display device that operates using the I2C protocol.
 */
public class LCD extends Display {

    /**
     * Constructs an LCD display with the specified protocol.
     *
     * @param protocol The communication protocol used by the LCD. Only I2C
     * protocol is supported.
     */
    public LCD(Protocol protocol) {
        if (protocol instanceof I2C) {
            this.state = State.OFF;
            this.protocol = protocol;
        } else {
            System.err.println("Warning: LCD is only compatible with the I2C protocol.");
            this.protocol = null;
            this.state = State.OFF;
        }
    }

    /**
     * Retrieves the name of the device.
     *
     * @return A string representing the name of the device, "LCD".
     */
    @Override
    public String getName() {
        return "LCD";
    }

    /**
     * Checks if a valid protocol is assigned to the LCD.
     *
     * @return True if a protocol is assigned, false otherwise.
     */
    @Override
    public boolean getProtocol() {
        return protocol != null;
    }

    /**
     * Turns the LCD ON and updates its state.
     */
    @Override
    public void turnON() {
        System.out.println(this.getName() + ": Turning ON.");
        state = State.ON;
    }

    /**
     * Turns the LCD OFF and updates its state.
     */
    @Override
    public void turnOFF() {
        System.out.println(this.getName() + ": Turning OFF.");
        state = State.OFF;
    }

    /**
     * Prints the specified data on the LCD screen.
     *
     * @param data The string data to be displayed on the LCD.
     */
    @Override
    public void printData(String data) {
        System.out.println(this.getName() + ": Printing \"" + data + "\".");
    }

    /**
     * Retrieves the current state of the LCD (ON/OFF).
     *
     * @return The current state of the device.
     */
    @Override
    public State getState() {
        return state;
    }
}
