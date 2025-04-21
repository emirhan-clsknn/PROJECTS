package HWSystem.Devices;

public abstract class WirelessIO extends Device {

    @Override
    public String getDevType() {
        return "WirelessIO";
    }

    public abstract String recvData();

    public abstract void sendData(String data);

}
