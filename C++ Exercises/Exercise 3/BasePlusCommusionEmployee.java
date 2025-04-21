
public class BasePlusCommusionEmployee extends CommisionEmployee {

    private double baseSalary;

    public BasePlusCommusionEmployee(String f, String l, String s, double g, double c, double salary) {
        super(f, l, s, g, c);
        baseSalary = salary;
    }

    public void setBaseSalary(double b) {
        baseSalary = (b < 0.0) ? 0.0 : b;
    }

    public double getBaseSalary() {
        return baseSalary;
    }

    @Override
    public String toString() {
        return String.format("%s %s; %s: $%,.2f",
                "base-salaried", super.toString(),
                "base salary", getBaseSalary()
        );
    }
}
