#ifndef BANKACCOUNTS_H
#define BANKACCOUNTS_H

#include "User.h"
#include <vector>
#include <string>
using namespace std;

class BankAccounts
{
public:
    BankAccounts();

    void addAccount(User newAccount);
    void removeAccount(const string &name);
    User getAccount(const string &name) const;
    void displayAccounts() const;
    double getTotalBalance() const;
    int getNumberOfAccounts() const;
    User &operator[](int index);
    const User &operator[](int index) const;

private:
    vector<User> accounts;
};

#endif
