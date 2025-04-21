#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount
{
public:
    BankAccount(int id, double balance, double rate);
    BankAccount(int id, int dollar, int cents, double rate);
    BankAccount();
    int getId() const;
    double getBalance() const;
    int getAccountDollar() const;
    int getAccountCents() const;
    double getRate() const;
    void update();
    void input();
    void output() const;
    void setId(int id);
    void setBalance(double balance);
    void setBalance(int dollar, int cents);
    void setDollar(int dollar);
    void setCents(int cents); // `double` yerine `int` olmalı
    void setRate(double rate);
    static int getNumberOfAccounts();

    const BankAccount operator+(const BankAccount &account2) const;
    const BankAccount operator-(const BankAccount &account2) const;
    const BankAccount operator-() const;
    const BankAccount operator*(double multiplier) const;
    const BankAccount operator/(double divisor) const;
    BankAccount operator++();
    BankAccount operator++(int);
    bool operator==(const BankAccount &account2) const;

private:
    int id;
    int accountDollar;
    int accountCents;
    double rate;
    static int numberOfAccounts; // Statik değişken sınıf dışında tanımlanmalı
};

#endif // BANKACCOUNT_H
