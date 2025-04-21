#ifndef VALUECELL_H
#define VALUECELL_H

#include <string>
#include <sstream>
#include <stdexcept> // For exception handling
#include "Cell.h"

using namespace std;   // Standard namespace for convenience
using namespace Cells; // Namespace for organizing related classes

namespace Cells
{
    // ValueCell class, inheriting from Cell
    // This class represents a cell that holds a generic value (string representation)
    class ValueCell : public Cell
    {
    protected:
        string value; // Value stored in the cell

    public:
        // Constructor initializes the ValueCell with an optional string value (default is an empty string)
        ValueCell(const string &value = "");

        // Move constructor for efficient resource transfer
        ValueCell(ValueCell &&other) noexcept;

        // Sets the value of the cell
        void setValue(const string &value);

        // Retrieves the value as a string
        string getStringValue() const override;

        // Retrieves the value as a double, returning 0.0 if conversion fails
        double getDoubleValue() const override;

        // Determines if the cell's value is numeric
        bool isNumber() const override;

        // Determines if the cell's value is a plain string (non-numeric)
        bool isString() const override;

        // Determines if the cell holds a formula (always false for ValueCell)
        bool isFormula() const override;
    };
}

#endif // VALUECELL_H
