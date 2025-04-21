package HWSystem.Devices;

/**
 * Represents a device capable of wireless communication. Extends the Device
 * class and provides abstract methods for receiving and sending data.
 */
public abstract class WirelessIO extends Device {

    /**
     * Retrieves the type of device. In this case, it's a "WirelessIO".
     *
     * @return A string representing the device type, "WirelessIO".
     */
    @Override
    public String getDevType() {
        return "WirelessIO";
    }

    /**
     * Receives data through the wireless communication channel. This method
     * must be implemented by subclasses.
     *
     * @return A string representing the received data.
     */
    public abstract String recvData();

    /**
     * Sends data through the wireless communication channel. This method must
     * be implemented by subclasses.
     *
     * @param data The data to be sent.
     */
    public abstract void sendData(String data);
}
