#include "DoubleValueCell.h"

namespace Cells
{
    // Override getDoubleValue to retrieve the cell's value as a double
    double DoubleValueCell::getDoubleValue() const
    {
        try
        {
            return ValueCell::getDoubleValue(); // Call the base class method to retrieve the value
        }
        catch (const invalid_argument &e)
        {
            // Handle invalid conversion to double
            cerr << "Error: " << e.what() << endl; // Log the error to standard error output
            throw;                                 // Rethrow the exception for further handling
        }
    }
}
