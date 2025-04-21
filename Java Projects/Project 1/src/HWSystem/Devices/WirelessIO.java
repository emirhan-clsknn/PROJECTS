package HWSystem.Devices;

public abstract class WirelessIO extends Device {

    @Override
    public String getDevType() {
        return "WirelessIO";
    }

    @Override
    public abstract String recvData();

    @Override
    public abstract void sendData(String data);

}
