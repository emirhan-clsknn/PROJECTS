
public class MyTestFramework {

    public static void assertEquals(Object expected, Object actual) {
        if (!expected.equals(actual)) {
            System.out.println("Test failed: expected " + expected + ", but got " + actual);
        } else {
            System.out.println("Test passed");
        }
    }

    public static void runTests() {
        GTUHashSet<String> set = new GTUHashSet<>();
        set.add("hello");
        assertEquals(true, set.contains("hello"));
        set.remove("hello");
        assertEquals(false, set.contains("hello"));

        GTUHashMap<String, Integer> map = new GTUHashMap<>();
        map.put("apple", 1);
        assertEquals(Integer.valueOf(1), map.get("apple"));
        map.remove("apple");
        assertEquals(null, map.get("apple"));
    }
}
