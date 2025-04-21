package HWSystem.Devices;

public abstract class TempSensor extends Sensor {

    @Override
    public String getSensType() {
        return "TempSensor";
    }

    @Override
    public String data2String() {

        return String.format("Temperature: %.2f °C", getTemp());

    }

    @Override
    public abstract float getTemp();
}
