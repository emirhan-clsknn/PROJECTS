
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Scanner;

public class SpellChecker {

    public static void main(String[] args) throws Exception {

        System.gc();
        Thread.sleep(100);

        long beforeMemory = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();

        GTUHashSet<String> dictionary = new GTUHashSet<>();
        BufferedReader reader = new BufferedReader(new FileReader("dictionary.txt"));
        String word;
        while ((word = reader.readLine()) != null) {
            dictionary.add(word.trim().toLowerCase());
        }
        reader.close();

        long afterMemory = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
        double usedMemoryMB = (afterMemory - beforeMemory) / (1024.0 * 1024.0);
        System.out.printf("Memory used while loading dictionary: %.2f MB%n", usedMemoryMB);

        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Enter a word: ");
            String input = scanner.nextLine().trim().toLowerCase();
            long start = System.nanoTime();

            if (dictionary.contains(input)) {
                System.out.println("Correct.");
            } else {
                System.out.println("Incorrect. Suggestions:");
                GTUHashSet<String> suggestions = new GTUHashSet<>();
                int minLen = Math.max(2, input.length() - 2);
                int maxLen = input.length() + 2;

                MyList<String> edit1Variants = EditDistanceHelper.generateEditDistance1(input);
                for (int i = 0; i < edit1Variants.size(); i++) {
                    String variant = edit1Variants.get(i);
                    if (dictionary.contains(variant) && variant.length() >= minLen && variant.length() <= maxLen) {
                        suggestions.add(variant);
                    }
                }

                for (int i = 0; i < edit1Variants.size(); i++) {
                    String variant1 = edit1Variants.get(i);
                    MyList<String> edit2Variants = EditDistanceHelper.generateEditDistance1(variant1);
                    for (int j = 0; j < edit2Variants.size(); j++) {
                        String variant2 = edit2Variants.get(j);
                        if (dictionary.contains(variant2) && variant2.length() >= minLen && variant2.length() <= maxLen) {
                            suggestions.add(variant2);
                        }
                    }
                }

                if (suggestions.size() == 0) {
                    System.out.println("No suggestions found.");
                } else {
                    System.out.println(suggestions);
                    System.out.println("Total collisions: " + suggestions.getCollisionCount());
                }
            }

            long end = System.nanoTime();
            System.out.printf("Completed in %.2f ms%n", (end - start) / 1e6);
        }
    }
}
