
import java.io.*;
import java.util.*;

/**
 * Main class for reading users from a configuration file, accepting task
 * assignments from the terminal, and executing tasks based on their priority
 * using a custom priority queue.
 */
public class Main {

    /**
     * Main method for the program.
     *
     * @param args the command-line arguments, expects one argument for the user
     * config file path
     */
    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Usage: java Main <user_config_file_path>");
            return;
        }

        String configPath = args[0];
        Map<Integer, MyUser> userMap = new HashMap<>();
        MyPriorityQueue<MyTask> taskQueue = new MyMinHeap<>();
        int taskIdCounter = 0;

        /**
         * Reads user priorities from the configuration file and populates the
         * userMap.
         */
        try (BufferedReader br = new BufferedReader(new FileReader(configPath))) {
            String line;
            int userId = 0;
            while ((line = br.readLine()) != null) {
                try {
                    int priority = Integer.parseInt(line.trim());
                    userMap.put(userId, new MyUser(userId, priority));
                    userId++;
                } catch (NumberFormatException e) {
                    System.err.println("Invalid number format in config file: " + line);
                    return;
                }
            }
        } catch (IOException e) {
            System.err.println("Failed to read user config file: " + configPath);
            return;
        }

        /**
         * Accepts task assignments from the terminal until "execute" is
         * entered.
         */
        try (Scanner scanner = new Scanner(System.in)) {
            while (scanner.hasNext()) {
                String input = scanner.nextLine().trim();
                if (input.equalsIgnoreCase("execute")) {
                    break;
                }

                try {
                    int userID = Integer.parseInt(input);
                    MyUser user = userMap.get(userID);
                    if (user == null) {
                        System.err.println("Invalid user ID: " + userID);
                        continue;
                    }
                    taskQueue.add(new MyTask(user, taskIdCounter++));
                } catch (NumberFormatException e) {
                    System.err.println("Invalid input: " + input);
                }
            }
        }

        /**
         * Executes and prints tasks based on priority order.
         */
        while (!taskQueue.isEmpty()) {
            System.out.println(taskQueue.poll());
        }
    }
}
