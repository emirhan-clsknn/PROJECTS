
public class EditDistanceHelper {

    public static MyList<String> generateEditDistance1(String word) {
        MyList<String> edits = new MyList<>();
        int len = word.length();

        for (int i = 0; i < len; i++) {
            edits.add(word.substring(0, i) + word.substring(i + 1));
        }

        for (int i = 0; i <= len; i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                edits.add(word.substring(0, i) + c + word.substring(i));
            }
        }

        for (int i = 0; i < len; i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != word.charAt(i)) {
                    edits.add(word.substring(0, i) + c + word.substring(i + 1));
                }
            }
        }

        return edits;
    }
}
