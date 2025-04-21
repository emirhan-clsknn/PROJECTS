package HWSystem.Devices;

public abstract class IMUSensor extends Sensor {

    @Override
    public String getSensType() {
        return "IMUSensor";
    }

    @Override
    public String data2String() {
        return String.format("Accel: %.2f, Rot: %.2f.", getAccel(), getRot());
    }

    public abstract float getAccel();

    public abstract float getRot();
}
