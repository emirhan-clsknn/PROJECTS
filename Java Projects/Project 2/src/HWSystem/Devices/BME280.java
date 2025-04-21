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
            System.err.println("BME280 support only I2C and SPI. ");
            this.protocol = null;
            this.state = State.OFF;
        }
    }

    @Override
    public String getName() {
        return "BME280";
    }

    @Override

    public boolean getProtocol() {
        return protocol != null;
    }

    @Override
    public float getTemp() {
        return 24.0f;
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
}
