
/**
 * Represents a user with a unique ID and a priority level. Users with lower
 * priority values are considered higher priority.
 */
public class MyUser {

    private Integer id;
    private Integer priority;

    /**
     * Constructs a new user with the specified ID and priority.
     *
     * @param id the unique ID of the user
     * @param priority the priority level of the user (lower value means higher
     * priority)
     * @complexity O(1)
     */
    public MyUser(Integer id, Integer priority) {
        this.id = id;
        this.priority = priority;
    }

    /**
     * Returns the ID of the user.
     *
     * @return the user ID
     * @complexity O(1)
     */
    public Integer getID() {
        return this.id;
    }

    /**
     * Returns the priority level of the user.
     *
     * @return the user priority
     * @complexity O(1)
     */
    public Integer getPriority() {
        return this.priority;
    }
}
