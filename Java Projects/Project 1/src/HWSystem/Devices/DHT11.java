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
        System.out.println(this.getName() + " is turn on!");
        state = State.ON;

        if (protocol != null) {
            protocol.write("Turn on " + getName());
        } else {
            System.err.println("Protocol is missing for " + getName());
        }
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

    public boolean getProtocol() {
        return protocol != null;
    }

    @Override
    public State getState() {
        return state;
    }

    @Override
    public float getTemp() {
        System.out.println(protocol.read());
        return getRandomFloat(2.0f, 50.0f);
    }

}
