#ifndef CELL_H
#define CELL_H

#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept> // For exception handling
using namespace std;

// Abstract Base Class: Cell
namespace Cells
{
    class Cell
    {
    public:
        virtual ~Cell() = default; // Virtual destructor for proper cleanup in derived classes

        // Pure virtual functions to be implemented by derived classes
        virtual string getStringValue() const = 0; // Returns the cell's value as a string
        virtual double getDoubleValue() const = 0; // Returns the cell's value as a double
        virtual bool isNumber() const = 0;         // Checks if the cell contains a numeric value
        virtual bool isString() const = 0;         // Checks if the cell contains a string value
        virtual bool isFormula() const = 0;        // Checks if the cell contains a formula
    };
}

#endif
