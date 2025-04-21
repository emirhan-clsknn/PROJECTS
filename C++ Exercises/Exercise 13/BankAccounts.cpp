#include "BankAccounts.h"
#include <iostream>

// Constructor
BankAccounts::BankAccounts() {}

// Method to add a new account
void BankAccounts::addAccount(User newAccount)
{
    accounts.push_back(newAccount);
}

// Method to remove an account by name
void BankAccounts::removeAccount(const string &name)
{
    for (auto it = accounts.begin(); it != accounts.end(); ++it)
    {
        if (it->getName() == name)
        {
            accounts.erase(it);
            return;
        }
    }
    cout << "Account with name \"" << name << "\" not found." << endl;
}

// Method to get an account by name
User BankAccounts::getAccount(const string &name) const
{
    for (const auto &account : accounts)
    {
        if (account.getName() == name)
        {
            return account;
        }
    }
    cout << "Account with name \"" << name << "\" not found." << endl;
    return User(); // Default user if not found
}

// Method to display all accounts
void BankAccounts::displayAccounts() const
{
    for (const auto &account : accounts)
    {
        cout << account << endl;
    }
}

// Method to get total balance of all accounts
double BankAccounts::getTotalBalance() const
{
    double total = 0.0;
    for (const auto &account : accounts)
    {
        total += account.getAmount();
    }
    return total;
}

// Method to get the number of accounts
int BankAccounts::getNumberOfAccounts() const
{
    return accounts.size();
}

User &BankAccounts::operator[](int index)
{
    if (index >= 0 && index < accounts.size())
    {
        return accounts[index];
    }
    throw out_of_range("Index out of range");
}

const User &BankAccounts::operator[](int index) const
{
    if (index >= 0 && index < accounts.size())
    {
        return accounts[index];
    }
    throw out_of_range("Index out of range");
}