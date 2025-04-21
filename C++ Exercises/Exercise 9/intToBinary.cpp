#include <iostream>
#include <string>
using namespace std;

int fac(int x)
{
    if (x == 1)
    {
        return 1;
    }
    return x * fac(x - 1);
}
int main()
{
    int num;
    string str;
    cout << "Enter a number: ";
    cin >> num;

    while (num != 0)
    {
        if (num % 2 == 1)
        {
            str = '1' + str;
        }
        else
        {
            str = '0' + str;
        }
        num = num / 2;
    }

    cout << "Binary equivalent: " << str;
    return 0;
}