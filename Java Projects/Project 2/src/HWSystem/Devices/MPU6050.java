package HWSystem.Devices;

import HWSystem.Protocols.I2C;
import HWSystem.Protocols.Protocol;

public class MPU6050 extends IMUSensor {

    public MPU6050(Protocol protocol) {
        if (!(protocol instanceof I2C)) {
            System.err.println("MPU6050 only supports I2C protocol.");
        } else {
            this.state = State.OFF;
            this.protocol = protocol;
        }
    }

    @Override
    public String getName() {
        return "MPU6050";
    }

    @Override
    public float getAccel() {
        return 1.00f;
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
    public float getRot() {
        return 0.50f;
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
