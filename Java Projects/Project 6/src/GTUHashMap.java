
@SuppressWarnings("unchecked")
public class GTUHashMap<K, V> {

    private Entry<K, V>[] table;
    private int size;
    private int capacity;
    private static final double LOAD_FACTOR = 0.6;
    private static final int INITIAL_CAPACITY = 101;
    private int collisionCount = 0;

    public GTUHashMap() {
        capacity = INITIAL_CAPACITY;
        table = new Entry[capacity];
        size = 0;
    }

    private int hash(K key) {
        return Math.abs(key.hashCode()) % capacity;
    }

    public int getCollisionCount() {
        return collisionCount;
    }

    public void resetCollisionCount() {
        collisionCount = 0;
    }

    public void put(K key, V value) {
        if ((double) size / capacity > LOAD_FACTOR) {
            rehash();
        }
        int index = hash(key);
        int originalIndex = index;
        int i = 1;
        while (table[index] != null && !table[index].isDeleted && !table[index].key.equals(key)) {
            index = (originalIndex + i * i) % capacity;
            i++;
            collisionCount++;  // Increase the collision count
        }
        if (table[index] == null || table[index].isDeleted) {
            size++;
        }
        table[index] = new Entry<>(key, value);
    }

    public V get(K key) {
        int index = hash(key);
        int originalIndex = index;
        int i = 1;
        while (table[index] != null) {
            if (!table[index].isDeleted && table[index].key.equals(key)) {
                return table[index].value;
            }
            index = (originalIndex + i) % capacity;
            i++;
        }
        return null;
    }

    public void remove(K key) {
        int index = hash(key);
        int originalIndex = index;
        int i = 1;
        while (table[index] != null) {
            if (!table[index].isDeleted && table[index].key.equals(key)) {
                table[index].isDeleted = true;
                size--;
                return;
            }
            index = (originalIndex + i) % capacity;
            i++;
        }
    }

    public boolean containsKey(K key) {
        return get(key) != null;
    }

    public int size() {
        return size;
    }

    private void rehash() {
        int oldCapacity = capacity;
        Entry<K, V>[] oldTable = table;
        capacity = nextPrime(2 * oldCapacity);
        table = new Entry[capacity];
        size = 0;

        for (Entry<K, V> entry : oldTable) {
            if (entry != null && !entry.isDeleted) {
                put(entry.key, entry.value);
            }
        }
    }

    private int nextPrime(int n) {
        while (!isPrime(n)) {
            n++;
        }
        return n;
    }

    private boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        if (n <= 3) {
            return true;
        }
        if (n % 2 == 0 || n % 3 == 0) {
            return false;
        }
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

    public K[] keySet() {

        int count = 0;
        for (Entry<K, V> entry : table) {
            if (entry != null && !entry.isDeleted) {
                count++;
            }
        }

        K[] keys = (K[]) new Object[count];
        int index = 0;
        for (Entry<K, V> entry : table) {
            if (entry != null && !entry.isDeleted) {
                keys[index++] = entry.key;
            }
        }
        return keys;
    }

    private static class Entry<K, V> {

        K key;
        V value;
        boolean isDeleted;

        Entry(K key, V value) {
            this.key = key;
            this.value = value;
            this.isDeleted = false;
        }
    }
}
