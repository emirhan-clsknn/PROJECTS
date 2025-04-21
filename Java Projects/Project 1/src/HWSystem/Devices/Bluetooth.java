package HWSystem.Devices;

import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.UART;

public class Bluetooth extends WirelessIO {

    public Bluetooth(Protocol protocol) {
        if (protocol instanceof UART) {
            this.state = State.OFF;
            this.protocol = protocol;
        } else {
            System.err.println("Warning: LCD is only compatible with the I2C protocol. Protocol is set to null.");
            this.protocol = null;
            this.state = State.OFF;
        }

    }

    @Override

    public boolean getProtocol() {
        return protocol != null;
    }

    @Override
    public String getName() {
        return "Bluetooth";
    }

    @Override
    public String recvData() {
        protocol.read();
        return this.getName() + " Data is Being Received. ";
    }

    @Override
    public void turnON() {
        System.out.println(this.getName() + " is turn on!");
        state = State.ON;

    }

    @Override
    public void turnOFF() {
        System.out.println(this.getName() + " is turn off!");
        state = State.OFF;

    }

    @Override
    public State getState() {
        return state;
    }

    @Override
    public void sendData(String data
    ) {
        protocol.write(data);
        System.out.println(this.getName() + " " + this.getDevType() + ": Sending Out Data: " + data);
    }

}
