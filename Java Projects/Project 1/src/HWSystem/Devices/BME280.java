package HWSystem.Devices;

import HWSystem.Protocols.I2C;
import HWSystem.Protocols.Protocol;
import HWSystem.Protocols.SPI;

public class BME280 extends TempSensor {

    public BME280(Protocol protocol) {
        if (protocol instanceof I2C || protocol instanceof SPI) {
            this.state = State.OFF;
            this.protocol = protocol;
        } else {
            System.err.println("BME280 support only I2C. ");
            this.protocol = null;
            this.state = State.OFF;
        }
    }

    @Override
    public String getName() {
        return "BME280";
    }

    @Override
    public void turnON() {
        System.out.println(this.getName() + " is turn on!");
        state = State.ON;

        if (protocol != null) {
            protocol.write("Turn On" + getName());
        } else {
            System.err.println("Protocol is missing for" + getName());
        }
    }

    @Override

    public boolean getProtocol() {
        return protocol != null;
    }

    @Override
    public float getTemp() {
        System.out.println(protocol.read());
        return getRandomFloat(2.0f, 50.0f);
    }

    @Override
    public void turnOFF() {
        System.out.println(this.getName() + " is turn off!");
        state = State.OFF;

        if (protocol != null) {
            protocol.write("Turn off " + getName());
        } else {
            System.err.println("Protocol is missing for " + getName());
        }
    }

    @Override
    public State getState() {
        return state;
    }
}
