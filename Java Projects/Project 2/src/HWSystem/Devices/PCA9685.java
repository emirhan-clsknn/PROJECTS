package HWSystem.Devices;

import HWSystem.Protocols.I2C;
import HWSystem.Protocols.Protocol;

public class PCA9685 extends MotorDriver {

    public PCA9685(Protocol protocol) {
        if (!(protocol instanceof I2C)) {
            System.err.println("PCA9685 supports only I2C.");
        } else {
            this.protocol = protocol;
            state = State.OFF;
        }
    }

    @Override
    public String getName() {
        return "PCA9685";
    }

    @Override
    public void setMotorSpeed(int speed) {
        if (protocol != null) {
            System.out.println(this.getName() + ": Setting speed to " + speed + ".");
        } else {
            System.err.println("Protocol is missing for " + getName());
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
    public State getState() {
        return state;
    }

    @Override

    public boolean getProtocol() {
        return protocol != null;
    }

}
