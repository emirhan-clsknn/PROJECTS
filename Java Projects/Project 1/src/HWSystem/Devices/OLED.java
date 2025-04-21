package HWSystem.Devices;

import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.SPI;

public class OLED extends Display {

    public OLED(Protocol protocol) {
        if (!(protocol instanceof SPI)) {
            System.err.println("SparkFunMD is compatible solely with the SPI protocol.");
        } else {
            this.state = State.OFF;
            this.protocol = protocol;
        }
    }

    @Override
    public String getName() {
        return "OLED";
    }

    @Override
    public void printData(String data) {
        System.out.println(this.getName() + " Printing Data...");
        protocol.write(data);
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

    public boolean getProtocol() {
        return protocol != null;
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
