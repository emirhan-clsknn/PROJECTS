// BankAccount.cpp

#include "BankAccount.h"
#include <iostream>

using namespace std;

// Constructor (Kurucu Fonksiyon)
BankAccount::BankAccount(string holder, double initialBalance)
{
    accountHolder = holder;
    balance = initialBalance;
    cout << "Hesap oluşturuldu. Hesap sahibi: " << accountHolder << endl;
}

// Bakiye sorgulama fonksiyonu
double BankAccount::getBalance() const
{
    return balance;
}

// Hesap sahibinin adını alma fonksiyonu
string BankAccount::getAccountHolder() const
{
    return accountHolder;
}

// Para yatırma fonksiyonu
void BankAccount::deposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
        cout << amount << " TL yatırıldı. Yeni bakiye: " << balance << " TL" << endl;
    }
    else
    {
        cout << "Geçersiz miktar!" << endl;
    }
}

// Para çekme fonksiyonu
void BankAccount::withdraw(double amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        cout << amount << " TL çekildi. Kalan bakiye: " << balance << " TL" << endl;
    }
    else if (amount > balance)
    {
        cout << "Yetersiz bakiye!" << endl;
    }
    else
    {
        cout << "Geçersiz miktar!" << endl;
    }
}
