
import java.util.ArrayList;

public class EmployeeTest {

    public static void main(String[] args) {
        // Employee tipinde bir ArrayList oluştur
        ArrayList<Employee> employees = new ArrayList<>();

        // Farklı çalışan türlerini oluştur ve listeye ekle
        employees.add(new SalariedEmployee("Alice", "Johnson", "123-45-6789", 800.00));
        employees.add(new HourlyEmployee("Bob", "Smith", "987-65-4321", 50.00, 42.0));
        employees.add(new CommisionEmployee("Charlie", "Brown", "111-22-3333", 10000.0, 0.06));

        employees.add(new BasePlusCommusionEmployee("Daisy", "Miller", "444-55-6666", 5000.0, 0.04, 300.0));

        // Her bir çalışan için bilgileri ve kazançlarını yazdır
        for (Employee employee : employees) {
            System.out.println(employee.toString());
            System.out.printf("Earnings: $%.2f\n\n", employee.earnings());
        }

        // Özellikleri güncelle ve tekrar yazdır
        System.out.println("Updating some employee details...\n");

        // Saatlik çalışan güncellemesi
        HourlyEmployee hourly = (HourlyEmployee) employees.get(1);
        hourly.setWage(55.00);
        hourly.setHours(45.0);

        // Maaşlı çalışan güncellemesi
        SalariedEmployee salaried = (SalariedEmployee) employees.get(0);
        salaried.setWeeklySalary(850.00);

        // BasePlus çalışan güncellemesi
        BasePlusCommusionEmployee basePlus = (BasePlusCommusionEmployee) employees.get(3);
        basePlus.setBaseSalary(350.0);

        // Güncellenmiş bilgileri yazdır
        for (Employee employee : employees) {
            System.out.println(employee.toString());
            System.out.printf("Updated Earnings: $%.2f\n\n", employee.earnings());
        }
    }
}
