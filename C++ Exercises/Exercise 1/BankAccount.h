#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <vector>
using namespace std;
class BankAccount
{
public:
    BankAccount(double balance, double rate);
    BankAccount(int dollars, int cents, double rate);
    BankAccount(int dollars, double rate);
    BankAccount();

    void update();
    void input();
    void output();

    double getBalance() const;
    int getDollars() const;
    int getCents() const;
    double getRate() const;

    void setBalance(double balance);
    void setBalance(int dollars, int cents);
    void setRate(double newRate);
    void addAccount(const BankAccount &account);

    void display() const;

    void displayAllAccounts() const;

private:
    int accountDollars;
    int accountCents;
    double rate;
    static vector<BankAccount> accounts;

    int dollarsPart(double amount);
    int centsPart(double amount);
    int round(double number);
    double fraction(double percent);
};

#endif
