package HWSystem.Devices;

import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.SPI;

/**
 * Represents an OLED display device that operates using the SPI protocol.
 */
public class OLED extends Display {

    /**
     * Constructs an OLED display with the specified protocol.
     *
     * @param protocol The communication protocol used by the OLED. Only SPI
     * protocol is supported.
     */
    public OLED(Protocol protocol) {
        if (!(protocol instanceof SPI)) {
            System.err.println("OLED is compatible solely with the SPI protocol.");
        } else {
            this.state = State.OFF;
            this.protocol = protocol;
        }
    }

    /**
     * Retrieves the name of the device.
     *
     * @return A string representing the name of the device, "OLED".
     */
    @Override
    public String getName() {
        return "OLED";
    }

    /**
     * Prints the specified data on the OLED screen.
     *
     * @param data The string data to be displayed on the OLED.
     */
    @Override
    public void printData(String data) {
        System.out.println(this.getName() + ": Printing \"" + data + "\".");
    }

    /**
     * Turns the OLED ON and updates its state.
     */
    @Override
    public void turnON() {
        System.out.println(this.getName() + ": Turning ON.");
        state = State.ON;
    }

    /**
     * Turns the OLED OFF and updates its state.
     */
    @Override
    public void turnOFF() {
        System.out.println(this.getName() + ": Turning OFF.");
        state = State.OFF;
    }

    /**
     * Checks if a valid protocol is assigned to the OLED.
     *
     * @return True if a protocol is assigned, false otherwise.
     */
    @Override
    public boolean getProtocol() {
        return protocol != null;
    }

    /**
     * Retrieves the current state of the OLED (ON/OFF).
     *
     * @return The current state of the device.
     */
    @Override
    public State getState() {
        return state;
    }
}
