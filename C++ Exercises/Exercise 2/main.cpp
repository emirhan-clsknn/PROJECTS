#include <iostream>
#include <vector>
#include "BankAccount.h"

using namespace std;

int main()
{
    // BankAccount sınıfından nesneler oluşturuyoruz
    BankAccount account1(1001, 150.75, 3.5); // ID, Balance (150.75), Rate (3.5%)
    BankAccount account2;                    // Default constructor ile oluşturulmuş nesne

    cout << "Account 1 Bilgileri:" << endl;
    account1.output();
    cout << endl;

    cout << "Account 2 Bilgileri:" << endl;
    account2.output();
    cout << endl;

    // Account 2'yi kullanıcıdan bilgi alarak dolduruyoruz
    cout << "Account 2 bilgilerini giriniz: " << endl;
    account2.input();
    cout << endl;

    cout << "Account 2 Güncel Bilgileri:" << endl;
    account2.output();
    cout << endl;

    // Güncellenmiş bakiyeleri ve hesap sayısını görüntüleyelim
    cout << "Account 1'in faizi güncelleniyor..." << endl;
    account1.update();
    account1.output();
    cout << endl;

    cout << "Account 2'nin faizi güncelleniyor..." << endl;
    account2.update();
    account2.output();
    cout << endl;

    vector<BankAccount> bankAccounts;
    bankAccounts.push_back(account1);
    bankAccounts.push_back(account2);
    cout << "Toplam Hesap Sayısı: " << bankAccounts.size() << endl;
    for (const auto account : bankAccounts)
    {
        cout << "Hesap Bilgileri:" << endl;
        account.output();
        cout << endl;
    }
    // Tüm hesapları listel
    // Toplam hesap sayısını görüntüleyelim
    cout << "Toplam Hesap Sayısı: " << BankAccount::getNumberOfAccounts() << endl;

    BankAccount account3;
    account3 = account1 + account2;
    cout << "Account 3 Bilgileri:" << endl;
    account3.output();
    cout << "Account 3'ün toplamı: " << account3.getRate()
         << endl;
    cout << endl;

    return 0;
}
