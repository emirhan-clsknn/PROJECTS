#include <iostream>

#include <string>

using namespace std;

class Car
{
public:
    int weight;
    string myColor;
    string myName;

    Car()
    { // constructor bu olay nesne oluşturulduğu anda çalışır
        weight = 0;
        myColor = "Black";
        myName = "Unknown";
    }
    Car(int weight, string myColor, string myName)
    {
        this->weight = weight;
        this->myColor = myColor;
        this->myName = myName;
    }

    void drive()
    {
        cout << "Drive Mode" << endl;
    }
    void stop();

    int speed(int mySpeed)
    {
        return mySpeed * 1.5;
    }
};

void Car::stop()
{
    cout << "Stop Mode" << endl;
}
int main()
{
    Car islem;
    islem.weight = 5;
    islem.myColor = "Red";
    islem.myName = "Skoda";

    Car islem2(2, "Yellow", "BMW");
    Car islem3;
    islem.drive();
    cout << "Car name: " << islem.myName << endl;
    cout << "Car color: " << islem.myColor << endl;
    cout << "Car weight: " << islem.weight << " kg" << endl;

    cout << "Car name: " << islem2.myName << endl;
    cout << "Car color: " << islem2.myColor << endl;
    cout << "Car weight: " << islem2.weight << " kg" << endl;

    cout << "Car name: " << islem3.myName << endl;
    cout << "Car color: " << islem3.myColor << endl;
    cout << "Car weight: " << islem3.weight << " kg" << endl;
}