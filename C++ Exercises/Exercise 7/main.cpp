// main.cpp

#include <iostream>
#include "BankAccount.h" // BankAccount sınıfını dahil et

using namespace std;

int main()
{
    // Yeni bir banka hesabı oluştur
    BankAccount account1("Ahmet Yilmaz", 500.0);

    // Bakiye sorgula
    cout << "Mevcut bakiye: " << account1.getBalance() << " TL" << endl;

    // Para yatır
    account1.deposit(250.0);

    // Para çek
    account1.withdraw(100.0);

    // Yetersiz bakiye durumu
    account1.withdraw(1000.0);

    return 0;
}
