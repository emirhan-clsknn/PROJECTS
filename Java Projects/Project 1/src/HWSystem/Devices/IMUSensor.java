package HWSystem.Devices;

public abstract class IMUSensor extends Sensor {

    @Override
    public String getSensType() {
        return "IMUSensor";
    }

    @Override
    public String data2String() {
        return String.format("Acceleration: %.2f m/s, Rotation: %.2f degrees/sec", getAccel(), getRot());
    }

    @Override
    public abstract float getAccel();

    @Override
    public abstract float getRot();
}
