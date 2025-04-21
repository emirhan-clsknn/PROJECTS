#ifndef SHAPE_H
#define SHAPE_H
#include <stdexcept>
#include <vector>
using namespace std;

namespace MynameSpace
{
    class Shape
    {
    public:
        virtual double calculateArea() const = 0;
        virtual double calculatePerimeter() const = 0;

        virtual ~Shape() = default;
    };

    class Circle : public Shape
    {
    private:
        double radius;

    public:
        Circle(double rad)
        {
            if (rad < 0)
            {
                throw invalid_argument("rad<0");
            }
            radius = rad;
        }
        double calculateArea() const override
        {
            return 3.14 * radius * radius;
        }
        double calculatePerimeter() const override
        {
            return 3.14 * 2 * radius;
        }
    };
    class Rectangle : public Shape
    {
    private:
        double width;
        double height;

    public:
        Rectangle(double w, double h)
        {
            if (w < 0 || h < 0)
            {
                throw invalid_argument("width height have problem");
            }
            width = w;
            height = h;
        };

        double calculateArea() const override
        {
            return width * height;
        }
        double calculatePerimeter() const override
        {
            return 2 * (width + height);
        }
    };
    template <typename T>
    T findMaxs(const vector<T> &shapes)
    {
        if (shapes.empty())
        {
            throw invalid_argument("Shape yok");
        }
        T largest = shapes[0];
        for (auto &shape : shapes)
        {
            if (shape->calculateArea() > largest->calculateArea())
            {
                largest = shape;
            }
        }
        return largest;
    }
};

#endif