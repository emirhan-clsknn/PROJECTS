
public class CommisionEmployee extends Employee {

    private double grossSales;
    private double comissionRate;

    public CommisionEmployee(String f, String l, String s, double g, double c) {
        super(f, l, s);
        setComissionRate(c);
        setGrossSales(g);
    }

    public void setGrossSales(double g) {
        grossSales = (g < 0.0) ? 0.0 : g;
    }

    public void setComissionRate(double c) {
        comissionRate = (c > 0.0 && c < 1.0) ? c : 0.0;
    }

    public double getGrossSales() {
        return grossSales;
    }

    public double getCommissionRate() {
        return comissionRate;
    }

    @Override
    public String toString() {
        return String.format("%s: %s \n%s: $%,.2f; %s: %.2f", "commission employee", super.toString(), "gross sales", getGrossSales(), "comisson rate ", getCommissionRate());
    }

    @Override
    public double earnings() {
        return getCommissionRate() * getGrossSales();
    }

}
