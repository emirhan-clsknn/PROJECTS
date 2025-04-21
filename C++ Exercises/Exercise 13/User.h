#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Money.h"

using namespace std;

class User
{
public:
    User(string name = " ", int age = 0, double amount = 0.0);

    const string getName() const { return name; }
    int getAge() const { return age; }
    double getAmount() const { return money.getAmount(); }
    // Operator Overloading
    const User operator+(const User &user2) const;
    const User operator-(const User &user2) const;
    const User operator*(double multiplier) const;
    const User operator/(double divisor) const;

    bool operator==(const User &user2) const;
    bool operator<(const User &user2) const;
    bool operator>(const User &user2) const;
    void operator()(double multiplier);

    friend ostream &operator<<(ostream &os, const User &user);

private:
    Money money;
    string name;
    int age;
};

#endif
