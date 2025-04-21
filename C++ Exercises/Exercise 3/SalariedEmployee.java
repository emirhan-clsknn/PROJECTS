
public class SalariedEmployee extends Employee {

    private double weeklySalary;

    public SalariedEmployee(String f, String l, String s, double salary) {
        super(f, l, s);
        setWeeklySalary(salary);
    }

    public void setWeeklySalary(double salary) {
        weeklySalary = (salary < 0.0) ? 0.0 : salary;
    }

    public double getWeeklySalary() {
        return weeklySalary;
    }

    @Override
    public String toString() {
        return String.format("salaried employee:%s\n%s: $%,.2f", super.toString(), "weekly salary", getWeeklySalary());
    }

    @Override
    public double earnings() {
        return getWeeklySalary();
    }

}
