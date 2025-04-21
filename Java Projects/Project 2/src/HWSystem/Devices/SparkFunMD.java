package HWSystem.Devices;

import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.SPI;

public class SparkFunMD extends MotorDriver {

    public SparkFunMD(Protocol protocol) {
        if (!(protocol instanceof SPI)) {
            System.err.println("SparkFunMD supports only SPI .");
        } else {
            this.protocol = protocol;
            state = State.OFF;
        }
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
            System.out.println(this.getName() + ": Setting speed to " + speed + ".");
        } else {
            System.err.println("Protocol is missing for " + getName());
        }
    }
}
