package HWSystem.Devices;

import HWSystem.Protocols.Protocol;

public abstract class Device {

    protected Protocol protocol;
    protected State state = State.OFF;

    public abstract boolean getProtocol();

    ;
    public abstract String getName();

    public abstract void turnOFF();

    public abstract void turnON();

    public abstract State getState();

    public abstract String getDevType();

    public String data2String() {
        System.err.println("Not supported yet.");
        return "";
    }

    public void printData(String string) {
        System.err.println("Not supported yet.");

    }

    public void setMotorSpeed(int speed) {
        System.err.println("Not supported yet.");
    }

    public String getSensType() {
        System.err.println("Not supported yet.");
        return "";
    }

    public void sendData(String data) {
        System.err.println("Not supported yet.");
    }

    public String recvData() {
        System.err.println("Not supported yet.");
        return "";
    }

    public float getAccel() {
        System.err.println("Not supported yet.");
        return 0;
    }

    public float getRot() {
        System.err.println("Not supported yet.");
        return 0;
    }

    public float getTemp() {
        System.err.println("Not supported yet.");
        return 0;
    }
};
