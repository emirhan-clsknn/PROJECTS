
import java.util.ArrayList;

/**
 * A min-heap implementation of a priority queue. Elements with lower values are
 * given higher priority.
 *
 * @param <T> the type of elements stored in the heap, must be Comparable
 */
public class MyMinHeap<T extends Comparable<T>> implements MyPriorityQueue<T> {

    private ArrayList<T> heap;

    /**
     * Constructs an empty MinHeap.
     *
     * Time Complexity: O(1)
     */
    public MyMinHeap() {
        heap = new ArrayList<>();
    }

    /**
     * Adds an element to the heap and restores heap order.
     *
     * @param t the element to add
     * @complexity O(log n) - due to heapify-up
     */
    @Override
    public void add(T t) {
        heap.add(t);
        heapifyUp(heap.size() - 1);
    }

    /**
     * Checks if the heap is empty.
     *
     * @return true if the heap is empty, false otherwise
     * @complexity O(1)
     */
    @Override
    public Boolean isEmpty() {
        return heap.isEmpty();
    }

    /**
     * Removes and returns the element with the highest priority (smallest
     * value).
     *
     * @return the root element of the heap, or null if the heap is empty
     * @complexity O(log n) - due to heapify-down
     */
    @Override
    public T poll() {
        if (isEmpty()) {
            return null;
        }
        T root = heap.get(0);
        T last = heap.remove(heap.size() - 1);
        if (!heap.isEmpty()) {
            heap.set(0, last);
            heapifyDown(0);
        }
        return root;
    }

    /**
     * Restores heap order from bottom to top starting at the given index.
     *
     * @param index the index to start heapifying up from
     * @complexity O(log n)
     */
    private void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap.get(index).compareTo(heap.get(parent)) < 0) {
                swap(index, parent);
                index = parent;
            } else {
                break;
            }
        }
    }

    /**
     * Swaps the elements at the two specified indices.
     *
     * @param i the first index
     * @param j the second index
     * @complexity O(1)
     */
    private void swap(int i, int j) {
        T tmp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, tmp);
    }

    /**
     * Restores heap order from top to bottom starting at the given index.
     *
     * @param index the index to start heapifying down from
     * @complexity O(log n)
     */
    private void heapifyDown(int index) {
        int left, right, smallest;
        while ((left = 2 * index + 1) < heap.size()) {
            right = left + 1;
            smallest = index;

            if (heap.get(left).compareTo(heap.get(smallest)) < 0) {
                smallest = left;
            }
            if (right < heap.size() && heap.get(right).compareTo(heap.get(smallest)) < 0) {
                smallest = right;
            }

            if (smallest != index) {
                swap(index, smallest);
                index = smallest;
            } else {
                break;
            }
        }
    }

}
