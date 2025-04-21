package HWSystem.Devices;

import HWSystem.Protocols.I2C;
import HWSystem.Protocols.Protocol;

public class LCD extends Display {

    public LCD(Protocol protocol) {
        if (protocol instanceof I2C) {
            this.state = State.OFF;
            this.protocol = protocol;
        } else {
            System.err.println("Warning: LCD is only compatible with the I2C protocol.");
            this.protocol = null;
            this.state = State.OFF;
        }
    }

    @Override
    public String getName() {
        return "LCD";
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
    public void printData(String data) {
        System.out.println(this.getName() + ": Printing \"" + data + "\".");
    }

    @Override
    public State getState() {
        return state;
    }

}
