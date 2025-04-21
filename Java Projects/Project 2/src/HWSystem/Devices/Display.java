package HWSystem.Devices;

public abstract class Display extends Device {

    @Override
    public String getDevType() {
        return "Display";
    }

    public abstract void printData(String data);

}
