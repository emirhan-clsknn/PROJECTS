package HWSystem.Protocols;

public interface Protocol {

    String getProtocolName();

    void write(String data);

    String read();

}
