package HWSystem.Devices;

public abstract class Sensor extends Device {

    @Override
    public String getDevType() {
        return "Sensor";
    }

    public abstract String getSensType();

    public abstract String data2String();

}
