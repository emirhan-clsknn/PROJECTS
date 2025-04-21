#include <iostream>

class DayOfYear
{

public:
    DayOfYear(int month, int day);

    int getMonth() const
    {
        return month;
    };
    int getDay() const
    {
        return day;
    };

private:
    int month;
    int day;
};
DayOfYear::DayOfYear(int month, int day) : month(month), day(day) {};

int main()
{
    DayOfYear day(12, 31);
    std::cout << "Day: " << day.getDay() << ", Month: " << day.getMonth() << std::endl;
}