#ifndef MONEY_H
#define MONEY_H

class Money
{
public:
    Money(int dollars = 0, int cents = 0);
    Money(double amount2);

    int getDollars() const;
    int getCents() const;
    double getAmount() const;

    void setAmount(double amount2);
    void setDollars(int dollars);
    void setCents(int cents);

private:
    int dollars;
    int cents;
    double amount;

    void normalize();
};

#endif
