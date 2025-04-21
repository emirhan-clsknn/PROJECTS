package HWSystem.Devices;

import HWSystem.Protocols.I2C;
import HWSystem.Protocols.Protocol;

public class LCD extends Display {

    public LCD(Protocol protocol) {
        if (protocol instanceof I2C) {
            this.state = State.OFF;
            this.protocol = protocol;
        } else {
            System.err.println("Warning: LCD is only compatible with the I2C protocol. Protocol is set to null.");
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
        System.out.println(this.getName() + " is turn on!");
        state = State.ON;

        if (protocol != null) {
            protocol.write("Turn On " + getName());
        } else {
            System.err.println("Protocol is missing for " + getName());
        }
    }

    @Override
    public void printData(String data) {
        System.out.println(this.getName() + " Printing Data...");
        protocol.write(data);
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
            protocol.write("TURN_OFF " + getName());
        } else {
            System.err.println("Protocol is missing for " + getName());
        }
    }

}
