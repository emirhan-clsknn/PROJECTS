package HWSystem.Protocols;

public interface Protocol {

    /**
     * Returns the name of the protocol.
     *
     * @return The name of the protocol.
     */
    String getProtocolName();

    /**
     * Writes data to the protocol.
     *
     * @param data The data to write to the protocol.
     */
    void write(String data);

    /**
     * Reads data from the protocol.
     *
     * @return The data read from the protocol.
     */
    String read();

    /**
     * Closes the protocol and performs any necessary cleanup.
     */
    void close();
}
