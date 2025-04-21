package HWSystem.Protocols;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Stack;

public class SPI implements Protocol {

    protected int portId;
    private ArrayList<String> commands;
    private String dir;

    /**
     * Constructs an SPI instance with the given port ID and log directory.
     *
     * @param portId The port ID associated with this SPI instance.
     * @param dir The directory where logs will be stored.
     */
    public SPI(int portId, String dir) {
        this.dir = dir;
        this.commands = new ArrayList<>();
        commands.add("clean");
        commands.add("Port Opened.");
        this.portId = portId;
    }

    /**
     * Logs the action performed on the port. Logs are stored in a file in the
     * specified directory.
     *
     * @param action The action to log.
     */
    private void logPortAction(String action) {

        String portName = getProtocolName();
        String logFileName = portName + "_" + this.portId + ".log";
        File logDir = new File(this.dir); // logs klasörünü temsil eden nesne

        // Eğer logs klasörü yoksa, oluştur
        if (!logDir.exists()) {
            boolean dirCreated = logDir.mkdirs();
            if (!dirCreated) {
                System.err.println("Error: Failed to create logs directory at " + logDir.getAbsolutePath());
                return;
            }
        }

        File logFile = new File(logDir, logFileName);
        Stack<String> logEntries = new Stack<>();

        if (!action.equals("clean")) {
            logEntries.push(action);

            if (logFile.exists()) {
                try (Scanner scanner = new Scanner(logFile)) {
                    while (scanner.hasNextLine()) {
                        logEntries.push(scanner.nextLine());
                    }
                } catch (IOException e) {
                    System.err.println("Error reading log file: " + e.getMessage());
                    return;
                }
            }
        }

        try (FileWriter writer = new FileWriter(logFile)) { // Overwrite to maintain order
            Iterator<String> iterator = logEntries.iterator();
            while (iterator.hasNext()) {
                writer.write(iterator.next() + "\n");
            }

        } catch (IOException e) {
            System.err.println("Error writing to log file: " + e.getMessage());
        }
    }

    /**
     * Returns the name of the protocol.
     *
     * @return The name of the protocol ("SPI").
     */
    @Override
    public String getProtocolName() {
        return "SPI";
    }

    /**
     * Writes the specified data to the protocol.
     *
     * @param data The data to write.
     */
    @Override
    public void write(String data) {
        commands.add("Writing \"" + data + "\".");
    }

    /**
     * Reads data from the protocol.
     *
     * @return A string representing the data read from the protocol.
     */
    @Override
    public String read() {
        commands.add("Reading.");
        return "Reading.";
    }

    /**
     * Closes the protocol and logs all actions performed.
     */
    @Override
    public void close() {
        Iterator<String> commandIterator = commands.iterator();
        while (commandIterator.hasNext()) {
            String action = commandIterator.next();
            logPortAction(action);
        }
    }

}
