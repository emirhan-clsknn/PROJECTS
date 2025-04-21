package HWSystem.Devices;

import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.SPI;
import HWSystem.Protocols.UART;

public class GY951 extends IMUSensor {

    public GY951(Protocol protocol) {
        if (!(protocol instanceof SPI || protocol instanceof UART)) {
            System.err.println("GY-951 is only compatible with SPI and UART protocols.");
        } else {
            this.state = State.OFF;
            this.protocol = protocol;
        }
    }

    @Override
    public String getName() {
        return "GY_951";
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
            protocol.write("Turn On " + getName());
        } else {
            System.err.println("Protocol is missing for " + getName());
        }
    }

    @Override
    public float getRot() {
        return getRandomFloat(2.0f, 50.0f);
    }

    @Override
    public State getState() {
        return state;
    }

    @Override

    public boolean getProtocol() {
        return protocol != null;
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
