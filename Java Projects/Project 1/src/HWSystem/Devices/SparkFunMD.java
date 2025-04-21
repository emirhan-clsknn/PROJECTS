package HWSystem.Devices;

import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.SPI;

public class SparkFunMD extends MotorDriver {

    public SparkFunMD(Protocol protocol) {
        if (!(protocol instanceof SPI)) {
            System.err.println("WiFi supports only SPI .");
        } else {
            this.protocol = protocol;
            state = State.OFF;
        }
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
    public void turnOFF() {
        System.out.println(this.getName() + " is turn off!");
        state = State.OFF;

        if (protocol != null) {
            protocol.write("Turn Off " + getName());
        } else {
            System.err.println("Protocol is missing for " + getName());
        }
    }

    @Override

    public boolean getProtocol() {
        return protocol != null;
    }

    @Override
    public String getName() {
        return "SparkFunMD";
    }

    @Override
    public State getState() {
        return state;
    }

    @Override
    public void setMotorSpeed(int speed) {
        if (protocol != null) {
            protocol.write("Setting Speed." + speed);
        } else {
            System.err.println("Protocol is missing for " + getName());
        }
    }
}
