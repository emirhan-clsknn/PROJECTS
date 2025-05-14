
public class GTUHashSet<E> {

    private static final Object DUMMY = new Object();
    private GTUHashMap<E, Object> map;

    public GTUHashSet() {
        map = new GTUHashMap<>();
    }

    public boolean add(E e) {
        if (!map.containsKey(e)) {
            map.put(e, DUMMY);
            return true;
        }
        return false;
    }

    public int getCollisionCount() {
        return map.getCollisionCount();
    }

    public void resetCollisionCount() {
        map.resetCollisionCount();
    }

    public void remove(E element) {
        map.remove(element);
    }

    public boolean contains(E element) {
        return map.containsKey(element);
    }

    public int size() {
        return map.size();
    }

    public boolean isEmpty() {
        return map.size() == 0;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("[");

        for (E element : map.keySet()) {
            sb.append(element);
            sb.append(", ");
        }

        if (sb.length() > 1) {
            sb.setLength(sb.length() - 2);
        }

        sb.append("]");
        return sb.toString();
    }
}
