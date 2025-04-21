#include "User.h"
#include "Money.h"

// Constructor
User::User(string name, int age, double amount) : name(name), age(age)
{
    money.setAmount(amount);
}

// Operator Overloading Implementations
const User User::operator+(const User &user2) const
{
    return User(this->name, this->age, this->money.getAmount() + user2.money.getAmount());
}

const User User::operator-(const User &user2) const
{
    return User(this->name, this->age, this->money.getAmount() - user2.money.getAmount());
}

const User User::operator*(double multiplier) const
{
    return User(this->name, this->age, this->money.getAmount() * multiplier);
}

const User User::operator/(double divisor) const
{
    if (divisor == 0)
    {
        cout << "Cannot divide by zero" << endl;
        return *this; // Bu durumda mevcut User objesini geri döndürüyoruz.
    }
    return User(this->name, this->age, this->money.getAmount() / divisor);
}

// Comparison Operators
bool User::operator==(const User &user2) const
{
    return this->money.getAmount() == user2.money.getAmount();
}

bool User::operator<(const User &user2) const
{
    return this->money.getAmount() < user2.money.getAmount();
}

bool User::operator>(const User &user2) const
{
    return this->money.getAmount() > user2.money.getAmount();
}

// Friend Function for Output
ostream &operator<<(ostream &os, const User &user)
{
    os << "Name: " << user.name << ", Age: " << user.age << ", Amount: $" << user.money.getAmount();

    return os;
}
void User::operator()(double multiplier)
{
    money.setAmount(money.getAmount() * multiplier);
}