package HWSystem.Devices;

import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.SPI;
import HWSystem.Protocols.UART;

public class Wifi extends WirelessIO {

    public Wifi(Protocol protocol) {
        if (!(protocol instanceof SPI || protocol instanceof UART)) {
            System.err.println("WiFi supports only SPI and UART protocols.");
        } else {
            this.protocol = protocol;
            state = State.OFF;
        }

    }

    @Override
    public String getName() {
        return "Wifi";
    }

    @Override
    public String recvData() {
        return this.getName() + ": Received \"" + "Some Data\".";
    }

    @Override
    public void sendData(String data) {
        System.out.println(this.getName() + ": Sending \"" + data + "\".");
    }

    @Override

    public boolean getProtocol() {
        return protocol != null;
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
