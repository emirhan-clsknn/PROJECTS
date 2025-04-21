package HWSystem.Devices;

import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.SPI;
import HWSystem.Protocols.UART;

/**
 * Represents a WiFi device that operates using SPI or UART protocols. Extends
 * the WirelessIO class and provides methods for data transmission and
 * reception.
 */
public class Wifi extends WirelessIO {

    /**
     * Constructs a WiFi device with the specified protocol. Ensures that the
     * protocol is either SPI or UART.
     *
     * @param protocol The communication protocol used by the WiFi device. Only
     * SPI and UART protocols are supported.
     */
    public Wifi(Protocol protocol) {
        if (!(protocol instanceof SPI || protocol instanceof UART)) {
            System.err.println("WiFi supports only SPI and UART protocols.");
        } else {
            this.protocol = protocol;
            state = State.OFF;
        }
    }

    /**
     * Retrieves the name of the device.
     *
     * @return A string representing the name of the device, "Wifi".
     */
    @Override
    public String getName() {
        return "Wifi";
    }

    /**
     * Receives data through the WiFi connection.
     *
     * @return A string representing the received data.
     */
    @Override
    public String recvData() {
        return this.getName() + ": Received \"" + "Some Data\".";
    }

    /**
     * Sends data over the WiFi connection.
     *
     * @param data The data to be sent via WiFi.
     */
    @Override
    public void sendData(String data) {
        System.out.println(this.getName() + ": Sending \"" + data + "\".");
    }

    /**
     * Checks if a valid protocol is assigned to the WiFi device.
     *
     * @return True if a protocol is assigned, false otherwise.
     */
    @Override
    public boolean getProtocol() {
        return protocol != null;
    }

    /**
     * Turns the WiFi device ON and updates its state.
     */
    @Override
    public void turnON() {
        System.out.println(this.getName() + ": Turning ON.");
        state = State.ON;
    }

    /**
     * Turns the WiFi device OFF and updates its state.
     */
    @Override
    public void turnOFF() {
        System.out.println(this.getName() + ": Turning OFF.");
        state = State.OFF;
    }

    /**
     * Retrieves the current state of the WiFi device (ON/OFF).
     *
     * @return The current state of the device.
     */
    @Override
    public State getState() {
        return state;
    }
}
