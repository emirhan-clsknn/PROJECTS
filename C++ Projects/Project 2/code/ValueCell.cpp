#include "ValueCell.h"

namespace Cells
{
    // Constructor initializes the ValueCell with an optional string value
    ValueCell::ValueCell(const string &value) : value(value) {}

    // Move constructor for efficient resource transfer
    ValueCell::ValueCell(ValueCell &&other) noexcept : value(std::move(other.value)) {}

    // Sets the value of the cell
    void ValueCell::setValue(const string &value)
    {
        this->value = value;
    }

    // Retrieves the value as a string
    string ValueCell::getStringValue() const
    {
        return value;
    }

    // Retrieves the value as a double, returning 0.0 if conversion fails
    double ValueCell::getDoubleValue() const
    {
        try
        {
            return stod(value);
        }
        catch (const invalid_argument &)
        {
            return 0.0; // Return 0.0 if the value cannot be converted to double
        }
    }

    // Determines if the cell's value is numeric
    bool ValueCell::isNumber() const
    {
        istringstream iss(value);
        double num;
        return (iss >> num) && iss.eof(); // Check if the string can be fully parsed as a double
    }

    // Determines if the cell's value is a plain string (non-numeric)
    bool ValueCell::isString() const
    {
        return !isNumber();
    }

    // Determines if the cell holds a formula (always false for ValueCell)
    bool ValueCell::isFormula() const
    {
        return false;
    }
}
