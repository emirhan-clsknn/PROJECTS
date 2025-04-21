package HWSystem.Devices;

import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.UART;

public class Bluetooth extends WirelessIO {

    public Bluetooth(Protocol protocol) {
        if (protocol instanceof UART) {
            this.state = State.OFF;
            this.protocol = protocol;

        } else {
            System.err.println("Warning: Bluetooth only support UART protocol.");
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
        return this.getName() + ": Received \"" + "Some Data\".";
    }

    @Override
    public void sendData(String data) {
        System.out.println(this.getName() + ": Sending \1" + data + "\".");
    }

    @Override
    public void turnON() {
        System.out.println(this.getName() + ": Turning ON.");
        state = State.ON;

    }

    @Override
    public void turnOFF() {
        System.out.println(this.getName() + ": Turning OFF.");
        state = State.OFF;

    }

    @Override
    public State getState() {
        return state;
    }

}
