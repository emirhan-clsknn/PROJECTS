package HWSystem.Devices;

import HWSystem.Protocols.OneWire;
import HWSystem.Protocols.Protocol;

public class DHT11 extends TempSensor {

    public DHT11(Protocol protocol) {
        if (protocol instanceof OneWire) {
            this.state = State.OFF;
            this.protocol = protocol;
        } else {
            System.err.println("DHT11 only supports OneWire protocol.");
            this.protocol = null;
            this.state = State.OFF;
        }

    }

    @Override
    public String getName() {
        return "DHT11";
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
    public State getState() {
        return state;
    }

    @Override
    public float getTemp() {
        return 24.00f;
    }

}
