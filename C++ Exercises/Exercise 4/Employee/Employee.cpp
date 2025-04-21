#include <string>
#include <iostream>
using namespace std;

class Employee
{
public:
    Employee(const string &n, const string &l, const string &s) : firstName(n), lastName(l), socialSecurityNumber(s) {};
    void setFirstName(const string &a)
    {
        firstName = a;
    }
    string getFirstName() const
    {
        return firstName;
    }
    void setLastName(const string &l)
    {
        lastName = l;
    }
    string getLastName() const
    {
        return lastName;
    }
    void setsocialSN(const string &s)
    {
        socialSecurityNumber = s;
    }
    string getSocial() const
    {
        return socialSecurityNumber;
    }
    virtual double earnings() const = 0;
    virtual void print() const
    {
        cout << "Name: " << getFirstName() << endl
             << "LastName: " << getLastName() << endl
             << "SocialNumber: " << getSocial() << endl;
    };
    virtual ~Employee() {};

private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
};

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(const string &n, const string &l, const string &s, double w) : Employee(n, l, s), weeklySalary(w) {};
    void setWeeklySalary(double w)
    {
        weeklySalary = w;
    }

    double getWeeklySalary() const
    {
        return weeklySalary;
    }
    double earnings() const override
    {
        return getWeeklySalary();
    }
    void print() const override
    {
        Employee::print();
        cout << "Weekly Salary: " << weeklySalary;
    };

    ~SalariedEmployee()
    {
    }

private:
    double weeklySalary;
};

class CommissionEmployee : public Employee
{
public:
    CommissionEmployee(const string &n, const string &l, const string &s, double w, double h) : Employee(n, l, s), grossSales(w), commissionRate(h) {};
    void setgrossSales(double w)
    {
        grossSales = w;
    }

    double getgrossSales() const
    {
        return grossSales;
    }
    void setcommissionRate(double w)
    {
        commissionRate = w;
    }

    double getcommissionRate() const
    {
        return commissionRate;
    }
    virtual double earnings() const override
    {
        return getgrossSales() * getcommissionRate();
    }
    virtual void print() const override
    {
        cout << "Commission Employe" << endl;
        Employee::print();
        cout << "Salary: " << earnings();
    };

    ~CommissionEmployee()
    {
    }

private:
    double grossSales;
    double commissionRate;
};

class HourlyEmployee : public Employee
{
public:
    HourlyEmployee(const string &n, const string &l, const string &s, double w, double h) : Employee(n, l, s), wage(w), hours(h) {};
    void setwage(double w)
    {
        wage = w;
    }

    double getwage() const
    {
        return wage;
    }
    void sethours(double w)
    {
        hours = w;
    }

    double gethours() const
    {
        return hours;
    }
    double earnings() const override
    {
        if (gethours() <= 40)
        {
            return getwage() * gethours();
        }
        return (40 * getwage()) + (gethours() - 40) * (getwage() * 1.5);
    }
    void print() const override
    {
        cout << "Hourly Employe" << endl;
        Employee::print();
        cout << "Salary: " << earnings();
    };

    ~HourlyEmployee()
    {
    }

private:
    double wage;
    double hours;
};
class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const string &n, const string &l, const string &s, double w, double h, double b) : CommissionEmployee(n, l, s, w, h), baseSalary(b) {};
    void setbaseSalary(double w)
    {
        baseSalary = w;
    }

    double getbaseSalary() const
    {
        return baseSalary;
    }

    double earnings() const override
    {
        return getbaseSalary() + CommissionEmployee::earnings();
    }
    void print() const override
    {
        cout << "BasePlusCommission Employe" << endl;
        CommissionEmployee::print();
        cout << "Salary: " << earnings();
    };

    ~BasePlusCommissionEmployee()
    {
    }

private:
    double baseSalary;
};

template <typename T>
void functsion(T value)
{
    cout << value;
}

int main()
{
    Employee *employees[] = {
        new SalariedEmployee("John", "Doe", "123-45-6789", 800.0),
        new CommissionEmployee("Jane", "Smith", "987-65-4321", 10000.0, 0.06),
        new HourlyEmployee("Bob", "Brown", "111-22-3333", 20.0, 50),
        new BasePlusCommissionEmployee("Alice", "Green", "444-55-6666", 5000.0, 0.04, 300.0)};

    for (Employee *e : employees)
    {
        e->print();
        cout << endl
             << endl;
        delete e;
    }
    int ss = 11;
    string sss = "asdas";

    return 0;
}
