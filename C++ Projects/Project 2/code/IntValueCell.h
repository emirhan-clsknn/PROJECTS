#ifndef INTVALUECELL_H
#define INTVALUECELL_H

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
    // IntValueCell: Represents a cell that holds integer values
    class IntValueCell : public ValueCell
    {
    public:
        // Constructor to initialize the cell with a string value (default is an empty string)
        IntValueCell(const string &value = "");

        // Returns the integer value of the cell as a double
        double getDoubleValue() const override;
    };
}

#endif // INTVALUECELL_H
