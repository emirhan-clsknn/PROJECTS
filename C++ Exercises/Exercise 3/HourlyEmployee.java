
public class HourlyEmployee extends Employee {

    private double wage;
    private double hours;

    public HourlyEmployee(String f, String l, String s, double w, double h) {
        super(f, l, s);
        wage = w;
        hours = h;
    }

    public void setWage(double w) {
        wage = (w < 0.0) ? 0.0 : w;
    }

    public void setHours(double h) {
        hours = (h < 0.0) ? 0.0 : h;
    }

    public double getWage() {
        return wage;
    }

    public double getHours() {
        return hours;
    }

    @Override

    public String toString() {
        return String.format("Hourly Employee: %s\n%s: $%,.2f", super.toString(), "hourly wage", getWage());
    }

    @Override
    public double earnings() {
        if (getHours() <= 40) {
            return getWage() * getHours();
        } else {
            return 40 * getWage() + (getHours() - 40) * getWage() * 1.5;
        }
    }
}
