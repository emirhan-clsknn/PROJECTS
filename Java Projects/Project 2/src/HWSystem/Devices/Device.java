package HWSystem.Devices;

import HWSystem.Protocols.Protocol;

public abstract class Device {

    protected Protocol protocol;
    protected int portId;
    protected int devId;
    protected State state = State.OFF;

    public int getPortId() {
        return portId;
    }

    public int getDevId() {
        return devId;
    }

    public void setDevId(int devId) {
        this.devId = devId;
    }

    public void setPortId(int portId) {
        this.portId = portId;
    }

    public abstract boolean getProtocol();

    public abstract String getName();

    public abstract void turnOFF();

    public abstract void turnON();

    public abstract State getState();

    public abstract String getDevType();

};
