#include "Shape.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <memory>

using namespace std;

int main()
{
    using namespace MynameSpace;
    try
    {
        shared_ptr<Shape> circle = make_shared<Circle>(5.0);
        shared_ptr<Shape> rectangle = make_shared<Rectangle>(-1, 5.0);

        vector<shared_ptr<Shape>> shapes = {circle, rectangle};

        for (const auto &shape : shapes)
        {
            cout << "Area: " << shape->calculateArea() << endl;
        }
        auto largestShape = findMaxs(shapes);
        cout << largestShape->calculateArea();
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}