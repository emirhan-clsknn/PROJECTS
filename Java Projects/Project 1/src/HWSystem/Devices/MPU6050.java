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
        System.out.println(protocol.read());
        System.out.print("Accel: ");
        return getRandomFloat(2.0f, 50.0f);
    }

    @Override
    public void turnON() {
        System.out.println(this.getName() + " is turn on!");
        state = State.ON;

        if (protocol != null) {
            protocol.write("TURN_ON " + getName());
        } else {
            System.err.println("Protocol is missing for " + getName());
        }
    }

    @Override
    public float getRot() {
        return getRandomFloat(2.0f, 50.0f);
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
