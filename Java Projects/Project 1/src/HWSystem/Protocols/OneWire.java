package HWSystem.Protocols;

public class OneWire implements Protocol {

    @Override
    public String getProtocolName() {
        return "OneWire";
    }

    @Override
    public void write(String data) {
        System.out.println("OneWire: Writing \"" + data + "\"");
    }

    @Override
    public String read() {
        return getProtocolName() + ": Reading.";
    }

}
