#include <iostream>
#include "BankAccount.h"
#include <vector>
using namespace std;

BankAccount::BankAccount(double balance, double rate)
{
    accountDollars = dollarsPart(balance);
    accountCents = centsPart(balance);
    this->rate = rate;
}

BankAccount::BankAccount(int dollars, int cents, double rate)
{
    accountDollars = dollars;
    accountCents = cents;
    this->rate = rate;
}

BankAccount::BankAccount(int dollars, double rate)
{
    accountDollars = dollars;
    accountCents = 0;
    this->rate = rate;
}

BankAccount::BankAccount()
{
    accountDollars = 0;
    accountCents = 0;
    rate = 0.0;
}

void BankAccount::update()
{
    double balance = getBalance();
    balance += balance * fraction(rate);
    setBalance(balance);
}

void BankAccount::input()
{
    double balanceAsDouble;
    cout << "Enter account balance $";
    cin >> balanceAsDouble;
    accountDollars = dollarsPart(balanceAsDouble);
    accountCents = centsPart(balanceAsDouble);
    cout << "Enter interest rate (NO percent sign): ";
    cin >> rate;
    setRate(rate);
}

void BankAccount::output()
{
    cout << "Balance: $" << getBalance() << endl;
    cout << "Interest Rate: " << rate << "%" << endl;
}

double BankAccount::getBalance() const
{
    return accountDollars + accountCents / 100.0;
}

int BankAccount::getDollars() const
{
    return accountDollars;
}

int BankAccount::getCents() const
{
    return accountCents;
}

double BankAccount::getRate() const
{
    return rate;
}

void BankAccount::addAccount(const BankAccount &account)
{
    accounts.push_back(account);
}

void BankAccount::displayAllAccounts() const
{
    for (const auto &account : accounts)
    {
        account.display();
    }
}
void BankAccount::setBalance(double balance)
{
    accountDollars = dollarsPart(balance);
    accountCents = centsPart(balance);
}

void BankAccount::setBalance(int dollars, int cents)
{
    accountDollars = dollars;
    accountCents = cents;
}

void BankAccount::setRate(double newRate)
{
    if (newRate >= 0)
        rate = newRate;
    else
    {
        cout << "Invalid rate. Program aborted." << endl;
        exit(1);
    }
}
vector<BankAccount> BankAccount::accounts;

void BankAccount::display() const
{
    cout << "Balance: $" << getBalance()
         << endl;
}

int BankAccount::dollarsPart(double amount)
{
    return static_cast<int>(amount);
}

int BankAccount::centsPart(double amount)
{
    double fractionalPart = amount - dollarsPart(amount);
    return round(fractionalPart * 100);
}

int BankAccount::round(double number)
{
    return static_cast<int>(number + 0.5);
}

double BankAccount::fraction(double percent)
{
    return percent / 100.0;
}
