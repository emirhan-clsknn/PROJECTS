#include <iostream>

#include <string>

using namespace std;

class MathOperations
{
public:
    int number1;
    int number2;

    MathOperations(int x, int y)
    { // constructor bu olay nesne oluşturulduğu anda çalışır
        number1 = x;
        number2 = y;
    }

    int addition()
    {
        return number1 + number2;
    }
    int subtraction()
    {
        return number1 - number2;
    }
    int multiplication()
    {
        return number1 * number2;
    }
    int division()
    {
        if (number2 != 0)
            return number1 / number2;
        else
            return 0; // Sıfıra bölünme hatası
    }
};

int main()
{
    MathOperations myMath(10, 5); // nesne oluşturuldu
    MathOperations myMath2(20, 4);
    cout << "Addition: " << myMath.addition() << endl;
    cout << "Subtraction: " << myMath.subtraction() << endl;
    cout << "Multiplication: " << myMath.multiplication() << endl;
    cout << "Division: " << myMath.division() << endl;
}