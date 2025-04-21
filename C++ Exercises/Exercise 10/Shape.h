#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <memory>
using namespace std;
const double PI = 3.14;
class Shape3D
{
private:
    string name;

protected:
    static size_t shapeCount;

public:
    Shape3D(const string &n) : name(n)
    {
        shapeCount++;
    };
    static size_t getCount()
    {
        return shapeCount;
    }
    static void setCount(size_t v)
    {
        shapeCount = v;
    }
    virtual double calculateVolume() const;
    virtual double calculateSurfaceArea() const;
    virtual ~Shape3D() = default;
};
size_t Shape3D::shapeCount = 0;
class Sphere : public Shape3D
{
private:
    double radius;

public:
    Sphere(const string &n, double r) : Shape3D(n), radius(r) {}
    void setRadius(double v)
    {
        radius = v;
    }
    double getRadius()
    {
        return radius;
    }
    double calculateVolume() const override
    {
        return 4 * PI * radius * radius * radius / 3;
    }
    double calculateSurfaceArea() const override
    {
        return 4 * PI * radius * radius;
    }
    ~Sphere() override { shapeCount--; };
};

class Cube : public Shape3D
{
private:
    double side;

public:
    Cube(const string &n, double s) : Shape3D(n), side(s) {}
    double getSide()
    {
        return side;
    }
    void setSide(double v)
    {
        side = v;
    }
    double calculateVolume() const override
    {
        return side * side * side;
    }
    double calculateSurfaceArea() const override
    {
        return 6 * side * side;
    }
    ~Cube() override { shapeCount--; }
};
class Cylinder : public Shape3D
{
private:
    double radius;
    double height;

public:
    Cylinder(const string &n, double r, double h) : Shape3D(n), radius(r), height(h) {}
    double getRadius()
    {
        return radius;
    }
    void setRadius(double v)
    {
        radius = v;
    }
    double getHeight()
    {
        return height;
    }
    void setHeight(double v)
    {
        height = v;
    }
    double calculateVolume() const override
    {
        return PI * radius * radius * height;
    }
    double calculateSurfaceArea() const override
    {
        return 2 * PI * radius * radius + 2 * PI * radius * height;
    }
    ~Cylinder() override { shapeCount--; }
};

class ShapeFactory
{
private:
    unique_ptr<unique_ptr<Shape3D>[]> shapes;
    size_t size;
    size_t capacity;
    void resize()
    {
        capacity += 10;
        auto newShapes = make_unique<unique_ptr<Shape3D>[]>(capacity);
        for (size_t i = 0; i < size; i++)
        {
            newShapes[i] = move(shapes[i]); // Mevcut şekilleri taşımak için move kullanılır
        }
        shapes = move(newShapes); // Yeni diziyi mevcut diziyle değiştir
    }

public:
    ShapeFactory(size_t capacity = 10)
    {
        shapes = make_unique<unique_ptr<Shape3D>[]>(capacity);
    };
    ShapeFactory(const ShapeFactory &other)
    {
        size = other.size;
        capacity = other.capacity;
        shapes = make_unique<unique_ptr<Shape3D>[]>(capacity);
        for (int i = 0; i < size; i++)
        {
            shapes[i] = make_unique<Shape3D>(other.shapes[i]);
        }
    }
    ShapeFactory(ShapeFactory &&other)
    {
        size = other.size;
        capacity = other.capacity;
        shapes = move(other.shapes);
        other.capacity = 0;
        other.capacity = 0;
    }
    ShapeFactory operator=(const ShapeFactory &other)
    {
        size = other.size;
        capacity = other.capacity;
        shapes = make_unique<unique_ptr<Shape3D>[]>(capacity);
        for (int i = 0; i < size; i++)
        {
            shapes[i] = make_unique<Shape3D>(other.shapes[i]);
        }
        return *this;
    }
    ShapeFactory operator=(ShapeFactory &&other)
    {
        size = other.size;
        capacity = other.capacity;
        shapes = move(other.shapes);
        other.capacity = 0;
        other.capacity = 0;
        return *this;
    }
    size_t getSize()
    {
        return size;
    }
    size_t getCapacity()
    {
        return capacity;
    }
    void addShape(unique_ptr<Shape3D> other)
    {
        if (capacity == size)
        {
            resize();
        }
        shapes[size++] = move(other);
    }
};

#endif