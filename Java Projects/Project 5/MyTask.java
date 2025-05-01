
/**
 * Represents a task submitted by a user. Tasks are comparable based on the
 * user's priority and task ID.
 */
public class MyTask implements Comparable<MyTask> {

    private MyUser user;
    private Integer id;

    /**
     * Constructs a new task with the given user and ID.
     *
     * @param user the user who submitted the task
     * @param id the unique ID of the task
     * @complexity O(1)
     */
    public MyTask(MyUser user, Integer id) {
        this.user = user;
        this.id = id;
    }

    /**
     * Returns the user associated with this task.
     *
     * @return the user who submitted the task
     * @complexity O(1)
     */
    public MyUser getUser() {
        return user;
    }

    /**
     * Returns the ID of this task.
     *
     * @return the task ID
     * @complexity O(1)
     */
    public Integer getId() {
        return id;
    }

    /**
     * Compares this task to another based on user priority and task ID. Lower
     * user priority means higher task priority. If priorities are equal,
     * earlier task ID has higher priority.
     *
     * @param other the other task to compare with
     * @return a negative integer, zero, or a positive integer as this task has
     * higher, equal, or lower priority than the specified task
     * @complexity O(1)
     */
    @Override
    public int compareTo(MyTask other) {
        int userPriorityCompare = Integer.compare(this.user.getPriority(), other.user.getPriority());
        if (userPriorityCompare != 0) {
            return userPriorityCompare;
        } else {
            return Integer.compare(this.id, other.id); // Earlier task has higher priority
        }
    }

    /**
     * Returns a string representation of the task.
     *
     * @return a string in the format "Request [id] User [userID]"
     * @complexity O(1)
     */
    @Override
    public String toString() {
        return "Request " + id + " User " + user.getID();
    }
}
