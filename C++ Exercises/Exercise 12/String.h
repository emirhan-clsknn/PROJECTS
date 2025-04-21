#ifndef STRING_H
#define STRING_H
#include <cstring>
#include <memory>
using namespace std;
class String
{
private:
    char *data;
    size_t size;
    size_t cap;
    void resize()
    {
        cap = cap * 2;
        char *newdata = new char[cap];
        for (int i = 0; i < size; i++)
        {
            newdata[i] = data[i];
        }
        data = newdata;
    }

public:
    String(char *st = "", size_t c)
    {
        size = strlen(st);
        cap = size * 2;
        data = new char[size * 2];
    }
    String(const String &other)
    {
        size = other.size;
        cap = other.cap;
        data = new char[cap];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }
    String(String &&other)
    {
        size = other.size;
        cap = other.cap;
        data = move(other.data);
        other.size = 0;
        other.cap = 0;
    }
    String &operator=(const String &other)
    {
        size = other.size;
        cap = other.cap;
        data = new char[cap];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
        return *this;
    }
    String &operator=(const char *other)
    {
        String(other);
    }
    String &operator=(String &&other)
    {
        size = other.size;
        cap = other.cap;
        data = move(other.data);
        other.size = 0;
        other.cap = 0;

        return *this;
    }
    ~String()
    {
        delete data;
    }
    size_t len()
    {
        return size;
    }
    String operator+(const String &other)
    {
        char *newData = new char[cap + other.cap];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        for (int k = size; k < size + other.size; k++)
        {
            newData[k] = other.data[k - size];
        }
    }
};
#endif

Shape *a = new Circle(10);

a.getbilmemne();

Linklist<int> arr = new Linklist<>();