#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(int id, double balance, double rate)
    : id(id), rate(rate)
{
    int dollar = balance;
    int cents = (balance - dollar) * 100;
    accountDollar = dollar;
    accountCents = cents;
    numberOfAccounts++;
}

BankAccount::BankAccount(int id, int dollar, int cents, double rate)
    : id(id), accountDollar(dollar), accountCents(cents), rate(rate)
{
    numberOfAccounts++;
}

BankAccount::BankAccount() : id(0), accountDollar(0), accountCents(0), rate(0)
{
    numberOfAccounts++;
}

int BankAccount::getId() const { return id; }

double BankAccount::getBalance() const
{
    return accountDollar + accountCents / 100.0;
}

int BankAccount::getAccountCents() const // int dönüş tipi
{
    return accountCents;
}

int BankAccount::getAccountDollar() const { return accountDollar; }

double BankAccount::getRate() const { return rate; }

void BankAccount::setBalance(double balance)
{
    int dollar = balance;
    int cents = (balance - dollar) * 100;
    setDollar(dollar);
    setCents(cents);
}

void BankAccount::setBalance(int dollar, int cents)
{
    setDollar(dollar);
    setCents(cents);
}

void BankAccount::setDollar(int dollar) { accountDollar = dollar; }

void BankAccount::setCents(int cents)
{
    if (cents >= 0 && cents <= 99)
        accountCents = cents;
    else
        std::cout << "Invalid cents. Program terminated." << std::endl;
}

void BankAccount::setRate(double rate)
{
    if (rate >= 0)
        this->rate = rate;
    else
        std::cout << "Invalid interest rate. Program terminated." << std::endl;
}

void BankAccount::setId(int id) { this->id = id; } // Fonksiyonun tanımı eklendi

void BankAccount::update()
{
    double balance = getBalance();
    balance += balance * rate / 100;
    setBalance(balance);
}

void BankAccount::input()
{
    std::cout << "Enter account ID: ";
    std::cin >> id;
    std::cout << "Enter balance: ";
    double balance;
    std::cin >> balance;
    setBalance(balance);
    std::cout << "Enter interest rate: ";
    std::cin >> rate;
}

void BankAccount::output() const
{
    std::cout << "Account ID: " << id << std::endl;
    std::cout << "Balance: $" << getBalance() << std::endl;
}

int BankAccount::numberOfAccounts = 0; // Statik değişken tanımı
int BankAccount::getNumberOfAccounts() { return numberOfAccounts; }

const BankAccount BankAccount::operator+(const BankAccount &account2) const
{
    double balance = getBalance() + account2.getBalance();
    return BankAccount(this->getId(), balance, this->getRate());
}
const BankAccount BankAccount::operator-(const BankAccount &account2) const
{
    double balance = getBalance() - account2.getBalance();
    return BankAccount(this->getId(), balance, this->getRate());
}
const BankAccount BankAccount::operator-() const
{
    return BankAccount(this->id, -this->getBalance(), this->getRate());
}
BankAccount BankAccount::operator++() const
{
    return BankAccount(this->getId, this->getBalance() + 1, this->getRate());
}
BankAccount BankAccount::operator++(int) const
{
    BankAccount temp = this;
    this->balance += 1;
    return temp;
}
