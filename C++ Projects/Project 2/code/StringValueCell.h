#ifndef STRINGVALUECELL_H
#define STRINGVALUECELL_H

#include <string>
#include "Cell.h"
#include "ValueCell.h"

using namespace std;   // Standard namespace for convenience
using namespace Cells; // Namespace for organizing related classes

namespace Cells
{
    // StringValueCell class, inheriting from ValueCell
    // This class represents a cell that contains a string value
    class StringValueCell : public ValueCell
    {
    public:
        // Constructor initializes the StringValueCell with an optional string value (default is an empty string)
        StringValueCell(const string &value = "");

        // Override isNumber to indicate that StringValueCell cannot be numeric
        bool isNumber() const override;
    };
}

#endif // STRINGVALUECELL_H
