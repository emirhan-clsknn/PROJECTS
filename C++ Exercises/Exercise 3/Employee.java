
public abstract class Employee {

    private String firstName;
    private String lastName;
    private String socialSecurityName;

    public Employee(String first, String last, String social) {
        firstName = first;
        lastName = last;
        socialSecurityName = social;
    }

    public void setFirstName(String first) {
        this.firstName = first;
    }

    public void setLastName(String last) {
        this.lastName = last;
    }

    public void socialSecurityName(String social) {
        this.socialSecurityName = social;
    }

    public String getFirstName() {
        return this.firstName;
    }

    public String getLastName() {
        return this.lastName;
    }

    public String getSocialSecurityName() {
        return this.socialSecurityName;
    }

    @Override
    public String toString() {
        return getFirstName() + " " + getLastName() + "\nSocial security number :" + getSocialSecurityName();
    }

    public abstract double earnings();
}
