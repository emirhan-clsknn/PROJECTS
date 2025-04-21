package HWSystem.Devices;

public abstract class MotorDriver extends Device {

    @Override
    public String getDevType() {
        return "MotorDriver";
    }

    @Override
    public abstract void turnOFF();

    @Override
    public abstract void turnON();

    @Override
    public abstract String getName();

    @Override
    public abstract State getState();

    public abstract void setMotorSpeed(int speed);
}
