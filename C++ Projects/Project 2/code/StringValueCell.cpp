#include "StringValueCell.h"

namespace Cells
{
    // Constructor initializes the StringValueCell with an optional string value
    StringValueCell::StringValueCell(const string &value) : ValueCell(value) {}

    // Override isNumber to indicate that StringValueCell cannot be numeric
    bool StringValueCell::isNumber() const
    {
        return false; // StringValueCell cannot be numeric
    }
}
