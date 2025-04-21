#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

class Money
{
public:
    Money() : dollars(0), cents(0) {}

    Money(double amount)
    {
        dollars = static_cast<int>(amount);
        cents = static_cast<int>(round((amount - dollars) * 100));
    }

    Money(int dollars, int cents) : dollars(dollars), cents(cents)
    {
        normalize();
    }

    Money(int dollars) : dollars(dollars), cents(0) {}

    double getAmount() const
    {
        return dollars + cents / 100.0;
    }

    int getDollars() const
    {
        return dollars;
    }

    int getCents() const
    {
        return cents;
    }

    void input()
    {
        std::string input;
        std::cout << "Enter amount (e.g., $12.34): ";
        std::getline(std::cin, input);
        // Basit bir format çözümü
        size_t dollarSign = input.find('$');
        if (dollarSign != std::string::npos)
        {
            input.erase(dollarSign, 1); // $ işaretini sil
        }
        double amount = std::stod(input);
        *this = Money(amount);
    }

    void output() const
    {
        std::cout << "$" << dollars << "." << std::setfill('0') << std::setw(2) << cents << std::endl;
    }

    friend const Money operator+(const Money &amount1, const Money &amount2)
    {
        return Money(amount1.dollars + amount2.dollars, amount1.cents + amount2.cents);
    }

    friend const Money operator-(const Money &amount1, const Money &amount2)
    {
        return Money(amount1.dollars - amount2.dollars, amount1.cents - amount2.cents);
    }

    friend bool operator==(const Money &amount1, const Money &amount2)
    {
        return (amount1.dollars == amount2.dollars) && (amount1.cents == amount2.cents);
    }

    friend const Money operator-(const Money &amount)
    {
        return Money(-amount.dollars, -amount.cents);
    }

private:
    int dollars; // Negatif miktar negatif dolarlara ve
    int cents;   // negatif sentlere temsil edilir.

    void normalize()
    {
        if (cents < 0)
        {
            dollars -= (abs(cents) + 99) / 100;
            cents = (cents % 100 + 100) % 100;
        }
        else if (cents >= 100)
        {
            dollars += cents / 100;
            cents = cents % 100;
        }
    }
};

int main()
{
    Money money1;         // Varsayılan yapıcı
    Money money2(15.75);  // double ile yapıcı
    Money money3(10, 50); // int ile yapıcı
    Money money4(20);     // Sadece dolarla yapıcı

    std::cout << "Money1: ";
    money1.input(); // Kullanıcıdan miktar al
    std::cout << "Money1: ";
    money1.output();

    std::cout << "Money2: ";
    money2.output();
    std::cout << "Money3: ";
    money3.output();
    std::cout << "Money4: ";
    money4.output();

    Money sum = money1 + money2;
    std::cout << "Sum of Money1 and Money2: ";
    sum.output();

    Money difference = money3 - money4;
    std::cout << "Difference of Money3 and Money4: ";
    difference.output();

    bool isEqual = (money2 == money1);
    std::cout << "Money2 and Money1 are equal: " << (isEqual ? "True" : "False") << std::endl;

    return 0;
}
