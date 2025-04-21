#include <iostream>
#include "User.h"
#include "Money.h"
#include "BankAccounts.h"
using namespace std;

int main()
{
    // Banka hesapları sınıfını başlat
    BankAccounts bank;

    // Bazı kullanıcı hesapları oluştur
    User user1("Alice", 30, 500.75);
    User user2("Bob", 25, 320.50);
    User user3("Charlie", 40, 1000.00);

    // Hesapları ekle
    bank.addAccount(user1);
    bank.addAccount(user2);
    bank.addAccount(user3);

    // Tum hesapları gruntule
    cout << "Tum hesaplar:" << endl;
    bank.displayAccounts();
    cout << endl;

    // Toplam bakiyeyi gster
    cout << "Toplam bakiye: $" << bank.getTotalBalance() << endl;
    cout << "Hesap sayisi: " << bank.getNumberOfAccounts() << endl;
    cout << endl;

    // Belirli bir hesabi al
    cout << "Bob'un hesabini al ve gruntule:" << endl;
    User foundUser = bank.getAccount("Bob");
    cout << foundUser << endl;
    cout << endl;

    // Bir hesabi cikar
    cout << "Charlie'nin hesabini cikar ve tum hesaplari yeniden gruntule:" << endl;
    bank.removeAccount("Charlie");
    bank.displayAccounts();
    cout << endl;

    // Toplam bakiyeyi guncelle ve yeniden gster
    cout << "Toplam bakiye (Charlie'nin cikarilmasindan sonra): $" << bank.getTotalBalance() << endl;
    cout << "Hesap sayisi: " << bank.getNumberOfAccounts() << endl;
    cout << endl;

    // Hesap işlemlerini test et
    cout << "Alice'in bakiyesini iki katina cikar:" << endl;
    User updatedUser = user1 * 2;
    cout << updatedUser << endl;

    cout << "Alice ve Bob'un toplam bakiyesi:" << endl;
    User combinedUser = user1 + user2;
    cout << combinedUser << endl;

    // () operatrunu kullanarak Alice'in bakiyesini iki katina cikar
    cout << "Alice'in bakiyesini iki katina cikar:" << endl;
    user1(2.0); // user1'in miktarini iki katina cikarir
    cout << user1 << endl;
    cout << endl;

    // [] operatrunu kullanarak bankadaki ilk kullaniciyi al ve gruntule
    cout << "Bankadaki ilk kullanici:" << endl;
    cout << bank[0] << endl;
    cout << endl;
    // Program sonlandirildi
    cout << "Program sonlandirildi." << endl;
    return 0;
}
