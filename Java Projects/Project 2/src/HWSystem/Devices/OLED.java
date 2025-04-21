package HWSystem.Devices;

import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.SPI;

public class OLED extends Display {

    public OLED(Protocol protocol) {
        if (!(protocol instanceof SPI)) {
            System.err.println("OLED is compatible solely with the SPI protocol.");
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
        System.out.println(this.getName() + ": Printing \"" + data + "\".");
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

    public boolean getProtocol() {
        return protocol != null;
    }

    @Override
    public State getState() {
        return state;
    }

}
