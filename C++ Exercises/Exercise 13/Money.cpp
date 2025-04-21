#include "Money.h"

// Constructors
Money::Money(int dollars, int cents) : dollars(dollars), cents(cents)
{
    normalize();
}

Money::Money(double amount2) : amount(amount2)
{
    dollars = amount2 / 100;
    cents = amount2 * 100 - dollars * 100;
}

// Getters
int Money::getDollars() const
{
    return dollars;
}

int Money::getCents() const
{
    return cents;
}

double Money::getAmount() const
{
    return amount;
}

// Setters
void Money::setAmount(double amount2)
{
    this->amount = amount2;
    dollars = amount2 / 100;
    cents = amount2 * 100 - dollars * 100;
}

void Money::setDollars(int dollars)
{
    this->dollars = dollars;
}

void Money::setCents(int cents)
{
    this->cents = cents;
    normalize();
}

// Private Helper Method to Normalize
void Money::normalize()
{
    if (cents < 100)
    {
        cents *= 100;
    }
    else
    {
        dollars += cents / 100;
        cents %= 100;
    }
}
