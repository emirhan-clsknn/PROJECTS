
/**
 * A generic interface for a priority queue.
 *
 * @param <T> the type of elements held in this queue, must be Comparable
 */
public interface MyPriorityQueue<T extends Comparable<T>> {

    /**
     * Adds an element to the priority queue.
     *
     * @param t the element to add
     * @complexity O(log n) - for typical binary heap-based implementation
     */
    void add(T t);

    /**
     * Retrieves and removes the highest-priority element from the queue.
     *
     * @return the element with the highest priority, or null if the queue is
     * empty
     * @complexity O(log n) - for typical binary heap-based implementation
     */
    T poll();

    /**
     * Checks whether the priority queue is empty.
     *
     * @return true if the queue contains no elements, false otherwise
     * @complexity O(1)
     */
    Boolean isEmpty();
}
