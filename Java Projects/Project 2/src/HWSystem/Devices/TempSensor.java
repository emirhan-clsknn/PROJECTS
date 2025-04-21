package HWSystem.Devices;

public abstract class TempSensor extends Sensor {

    @Override
    public String getSensType() {
        return "TempSensor";
    }

    @Override
    public String data2String() {

        return String.format("Temp: %.2fC.", getTemp());

    }

    public abstract float getTemp();
}
