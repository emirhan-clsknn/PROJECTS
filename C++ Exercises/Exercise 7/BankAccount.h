// BankAccount.h

#ifndef BANKACCOUNT_H // Header koruma
#define BANKACCOUNT_H

#include <string>
using namespace std;

class BankAccount
{
private:
    string accountHolder; // Hesap sahibinin adı
    double balance;       // Hesap bakiyesi

public:
    // Constructor
    BankAccount(string holder, double initialBalance);

    // Accessor: Bakiye sorgulama
    double getBalance() const;

    // Accessor: Hesap sahibinin adını alma
    string getAccountHolder() const;

    // Mutator: Para yatırma
    void deposit(double amount);

    // Mutator: Para çekme
    void withdraw(double amount);
};

#endif
