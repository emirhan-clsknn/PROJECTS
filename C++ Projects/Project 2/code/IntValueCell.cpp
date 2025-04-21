#include "IntValueCell.h"

namespace Cells
{
    // Constructor to initialize the cell with a string value
    IntValueCell::IntValueCell(const string &value) : ValueCell(value) {}

    // Returns the integer value of the cell as a double
    double IntValueCell::getDoubleValue() const
    {
        try
        {
            // Convert the string value to an integer
            return stoi(value);
        }
        catch (const invalid_argument &)
        {
            // Handle invalid conversion (non-integer strings)
            throw runtime_error("Invalid value conversion in IntValueCell: " + value);
        }
        catch (const out_of_range &)
        {
            // Handle out-of-range error during conversion
            throw runtime_error("Value out of range in IntValueCell: " + value);
        }
    }
}
