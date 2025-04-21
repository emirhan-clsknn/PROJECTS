package HWSystem.Protocols;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Stack;

public class I2C implements Protocol {

    protected int portId;
    private ArrayList<String> commands;
    private String dir;

    /**
     * Constructs an I2C protocol with the specified port ID and directory for
     * logging.
     *
     * @param portId The port ID for I2C communication.
     * @param dir The directory where log files will be stored.
     */
    public I2C(int portId, String dir) {
        this.dir = dir;
        this.commands = new ArrayList<>();
        commands.add("clean");
        commands.add("Port Opened.");
        this.portId = portId;
    }

    /**
     * Logs an action (such as a write or read operation) to a log file.
     *
     * @param action The action to log (e.g., "Writing", "Reading").
     */
    private void logPortAction(String action) {

        String portName = getProtocolName();
        String logFileName = portName + "_" + this.portId + ".log";
        File logDir = new File(this.dir); // Directory for logs

        // Create the logs directory if it doesn't exist
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

            // Read the existing log file if it exists
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
     * @return The name of the protocol, "I2C".
     */
    @Override
    public String getProtocolName() {
        return "I2C";
    }

    /**
     * Writes data to the I2C protocol.
     *
     * @param data The data to write to the protocol.
     */
    @Override
    public void write(String data) {
        commands.add("Writing \"" + data + "\".");
    }

    /**
     * Reads data from the I2C protocol.
     *
     * @return A string indicating the action of reading.
     */
    @Override
    public String read() {
        commands.add("Reading.");
        return "Reading.";
    }

    /**
     * Closes the I2C protocol and logs the actions taken.
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
