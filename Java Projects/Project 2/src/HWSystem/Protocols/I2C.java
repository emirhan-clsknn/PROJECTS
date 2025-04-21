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

    public I2C(int portId, String dir) {
        this.dir = dir;
        this.commands = new ArrayList<>();
        commands.add("clean");
        commands.add("Port Opened.");
        this.portId = portId;
    }

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

    @Override
    public String getProtocolName() {
        return "I2C";
    }

    @Override
    public void write(String data) {
        commands.add("Writing \"" + data + "\".");
    }

    @Override
    public String read() {
        commands.add("Reading.");
        return "Reading.";
    }

    @Override
    public void close() {
        Iterator<String> commandIterator = commands.iterator();
        while (commandIterator.hasNext()) {
            String action = commandIterator.next();
            logPortAction(action);
        }
    }

}
