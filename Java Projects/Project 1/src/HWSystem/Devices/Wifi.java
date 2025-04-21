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
        return "Wifi.";
    }

    @Override
    public String recvData() {
        protocol.read();
        return this.getName() + " Data is Being Received. ";
    }

    @Override
    public void sendData(String data) {
        protocol.write(data);
        System.out.println(this.getName() + " " + this.getDevType() + ": Sending Out Data: " + data);
    }

    @Override

    public boolean getProtocol() {
        return protocol != null;
    }

    @Override
    public void turnON() {
        System.out.println(this.getName() + " is turn on!");
        state = State.ON;

        if (protocol != null) {
            protocol.write("Turn On " + getName());
        } else {
            System.err.println("Protocol is missing for " + getName());
        }
    }

    @Override
    public State getState() {
        return state;
    }

    @Override
    public void turnOFF() {
        System.out.println(this.getName() + " is turn off!");
        state = State.OFF;

        if (protocol != null) {
            protocol.write("Turn Off " + getName());
        } else {
            System.err.println("Protocol is missing for " + getName());
        }
    }

}
