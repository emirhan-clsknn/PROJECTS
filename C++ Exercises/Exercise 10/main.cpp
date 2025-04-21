#include "Shape.h"
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    // Step 1: Create a CustomDynamicArray to hold 3 ShapeFactory objects
    vector<ShapeFactory> factories(3);

    // Step 2: Populate each ShapeFactory with 3 different Shape3D objects
    for (size_t i = 0; i < factories.size(); ++i)
    {
        factories[i].addShape(make_unique<Sphere>("Sphere_" + to_string(i + 1), i + 2.0));
        factories[i].addShape(make_unique<Cube>("Cube_" + to_string(i + 1), i + 1.5));
        factories[i].addShape(make_unique<Cylinder>("Cylinder_" + to_string(i + 1), i + 3.0, i + 1.0));
    }

    // Step 3: Display all shapes in all factories
    for (size_t i = 0; i < factories.size(); ++i)
    {
        cout << "Factory " << i + 1 << " Shapes:" << endl;
        factories[i].displayShapes();
        cout << "=====================================" << endl;
    }

    // Step 4: Check for temporary shape inside if statement
    if (true)
    {
        auto tempShape = make_unique<Cube>("Temporary Cube", 4.0);
        cout << "Temporary Shape created inside if statement:" << endl;
        tempShape->displayProperties();
    }
    cout << "After the if statement, the temporary shape is gone!" << endl;

    // Step 5: Use dynamic_cast to count how many Cube objects were created
    int cubeCount = 0;
    for (size_t i = 0; i < factories.size(); ++i)
    {
        for (size_t j = 0; j < factories[i].getSize(); ++j)
        {
            // Use dynamic_cast to check if the shape is a Cube
            if (auto *cube = dynamic_cast<Cube *>(factories[i][j]))
            {
                cubeCount++;
            }
        }
    }

    // Step 6: Display the count of Cube objects
    cout << "Total number of Cube objects created: " << cubeCount << endl;

    return 0;
}