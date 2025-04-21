#include <iostream>
#include <vector>
#include "BankAccount.h"
using namespace std;

int main()
{
    // İlk hesap: Başlangıç bakiyesi ve faiz oranı ile
    BankAccount account1(100.50, 5.0);

    // Hesap bilgilerini göster
    cout << "Account 1 initial details:" << endl;
    account1.output();

    // Faiz ekleyelim (1 yıl boyunca basit faiz)
    account1.update();
    cout << "\nAfter applying interest for 1 year:" << endl;
    account1.output();

    // İkinci hesap: Dolar, cent ve faiz oranı ile
    BankAccount account2(150, 25, 3.5);
    cout << "\nAccount 2 initial details:" << endl;
    account2.output();

    // Bakiyeyi elle ayarlayalım
    account2.setBalance(200, 75);
    account2.setRate(4.0);
    cout << "\nAfter setting new balance and interest rate for Account 2:" << endl;
    account2.output();

    // Faiz ekleyelim (1 yıl boyunca basit faiz)
    account2.update();
    cout << "\nAfter applying interest for 1 year to Account 2:" << endl;
    account2.output();

    // Üçüncü hesap: Varsayılan başlangıç (0.00 bakiye ve %0 faiz)
    BankAccount account3;
    cout << "\nAccount 3 initial details (default constructor):" << endl;
    account3.output();

    BankAccount bank;
    bank.addAccount(account1);
    bank.addAccount(account2);
    bank.addAccount(account3);

    bank.displayAllAccounts();
    return 0;
}
