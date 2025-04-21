#ifndef DOUBLEVALUECELL_H
#define DOUBLEVALUECELL_H

#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept> // For exception handling
#include "Cell.h"
#include "ValueCell.h"

using namespace std;   // Standard namespace for convenience
using namespace Cells; // Cells namespace for organizing related classes

namespace Cells
{
    // DoubleValueCell: A derived class of ValueCell specialized for handling double values
    class DoubleValueCell : public ValueCell
    {
    public:
        // Constructor that initializes the cell with a string value (default is an empty string)
        DoubleValueCell(const string &value = "") : ValueCell(value) {}

        // Override getDoubleValue to retrieve the cell's value as a double
        double getDoubleValue() const override;
    };
}

#endif // DOUBLEVALUECELL_H
