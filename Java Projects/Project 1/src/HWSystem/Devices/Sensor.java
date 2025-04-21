package HWSystem.Devices;

public abstract class Sensor extends Device {

    @Override
    public String getDevType() {
        return "Sensor";
    }

    @Override
    public abstract String getSensType();

    @Override
    public abstract String data2String();

    public static float getRandomFloat(float min, float max) {
        return min + (float) Math.random() * (max - min);
    }
}
