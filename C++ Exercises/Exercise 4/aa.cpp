#include <iostream>
#include <exception>
using namespace std;

// Özel istisna sınıfı
class CustomException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Custom exception occurred!";
    }
};

int main()
{
    try
    {
        throw CustomException();
    }
    catch (const exception &e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
    return 0;
}