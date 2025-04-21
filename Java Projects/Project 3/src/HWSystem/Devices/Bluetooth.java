package HWSystem.Devices;

import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.UART;

/**
 * Represents a Bluetooth wireless communication device. This class extends
 * WirelessIO and only supports the UART protocol.
 */
public class Bluetooth extends WirelessIO {

    /**
     * Constructs a Bluetooth device with the specified protocol. If the
     * protocol is not an instance of UART, a warning is displayed.
     *
     * @param protocol The communication protocol to be used.
     */
    public Bluetooth(Protocol protocol) {
        if (protocol instanceof UART) {
            this.state = State.OFF;
            this.protocol = protocol;
        } else {
            System.err.println("Warning: Bluetooth only supports UART protocol.");
            this.protocol = null;
            this.state = State.OFF;
        }
    }

    /**
     * Checks if the Bluetooth device has a valid protocol.
     *
     * @return true if a protocol is set, false otherwise.
     */
    @Override
    public boolean getProtocol() {
        return protocol != null;
    }

    /**
     * Retrieves the name of the device.
     *
     * @return The name "Bluetooth".
     */
    @Override
    public String getName() {
        return "Bluetooth";
    }

    /**
     * Simulates receiving data over Bluetooth.
     *
     * @return A string representing received data.
     */
    @Override
    public String recvData() {
        return this.getName() + ": Received \"Some Data\".";
    }

    /**
     * Simulates sending data over Bluetooth.
     *
     * @param data The data to be sent.
     */
    @Override
    public void sendData(String data) {
        System.out.println(this.getName() + ": Sending \"" + data + "\".");
    }

    /**
     * Turns on the Bluetooth device.
     */
    @Override
    public void turnON() {
        System.out.println(this.getName() + ": Turning ON.");
        state = State.ON;
    }

    /**
     * Turns off the Bluetooth device.
     */
    @Override
    public void turnOFF() {
        System.out.println(this.getName() + ": Turning OFF.");
        state = State.OFF;
    }

    /**
     * Retrieves the current state of the Bluetooth device.
     *
     * @return The current state (ON or OFF).
     */
    @Override
    public State getState() {
        return state;
    }
}
