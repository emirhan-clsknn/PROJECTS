#ifndef FORMULACELL_H
#define FORMULACELL_H

#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept> // For exception handling
#include "Cell.h"

using namespace std;   // Standard namespace for convenience
using namespace Cells; // Cells namespace for organizing related classes

namespace Cells
{
    // FormulaCell: Represents a cell that holds a formula
    class FormulaCell : public Cell
    {
    private:
        string formula; // Formula stored in the cell
        string value;   // The evaluated value of the formula

    public:
        // Constructor to initialize the formula and value
        FormulaCell(const string &formula = "", const string &val = "");

        // Move constructor for efficient resource transfer
        FormulaCell(FormulaCell &&other) noexcept;

        // Sets the formula for the cell
        void setFormula(const string &formula);

        // Sets the evaluated value of the formula
        void setValue(const string &value);

        // Returns the formula as a string
        string getStringValue() const override;

        // Returns the evaluated value as a double
        double getDoubleValue() const override;

        // Indicates if the cell is numeric (always false for FormulaCell)
        bool isNumber() const override;

        // Indicates if the cell is a plain string (always false for FormulaCell)
        bool isString() const override;

        // Indicates if the cell contains a formula (always true for FormulaCell)
        bool isFormula() const override;
    };
}

#endif // FORMULACELL_H
