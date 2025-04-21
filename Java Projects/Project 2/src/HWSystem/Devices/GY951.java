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
        return 1.0f;
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
    public State getState() {
        return state;
    }

    @Override

    public boolean getProtocol() {
        return protocol != null;
    }

}
