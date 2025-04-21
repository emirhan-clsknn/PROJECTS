#include "FormulaCell.h"

namespace Cells
{
    // Constructor to initialize the formula and value
    FormulaCell::FormulaCell(const string &formula, const string &val) : formula(formula), value(val) {}

    // Move constructor for efficient resource transfer
    FormulaCell::FormulaCell(FormulaCell &&other) noexcept : formula(std::move(other.formula)) {}

    // Sets the formula for the cell
    void FormulaCell::setFormula(const string &formula)
    {
        this->formula = formula;
    }

    // Sets the evaluated value of the formula
    void FormulaCell::setValue(const string &value)
    {
        this->value = value;
    }

    // Returns the formula as a string
    string FormulaCell::getStringValue() const
    {
        return formula;
    }

    // Returns the evaluated value as a double
    double FormulaCell::getDoubleValue() const
    {
        try
        {
            return stod(value); // Convert the string value to double
        }
        catch (const invalid_argument &)
        {
            // Handle invalid string-to-double conversion
            throw runtime_error("Invalid value conversion in FormulaCell: " + value);
        }
        catch (const out_of_range &)
        {
            // Handle out-of-range error during conversion
            throw runtime_error("Value out of range in FormulaCell: " + value);
        }
    }

    // Indicates if the cell is numeric (always false for FormulaCell)
    bool FormulaCell::isNumber() const
    {
        return false;
    }

    // Indicates if the cell is a plain string (always false for FormulaCell)
    bool FormulaCell::isString() const
    {
        return false;
    }

    // Indicates if the cell contains a formula (always true for FormulaCell)
    bool FormulaCell::isFormula() const
    {
        return true;
    }
}
