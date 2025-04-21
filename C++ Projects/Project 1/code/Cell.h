#ifndef CELL_H
#define CELL_H

#include <string>
using namespace std;

class Cell
{
public:
    // Default constructor
    Cell();

    // Set a value for the cell
    void setValue(const string &value);

    // Get the value of the cell as a string
    string getStringValue() const;

    // Get the value of the cell as a double (numeric value)
    double getDoubleValue() const;

    // Get the formula of the cell
    string getFormula() const;

    // Set a formula for the cell
    void setFormula(const string &formula);

    // Set a new value for the cell, clearing the formula
    void setNewValue(const string &value);

    // Check if the cell's value is numeric
    bool isNumber() const;

    // Check if the cell's value is a string (non-numeric and no formula)
    bool isString() const;

    // Check if the cell contains a formula
    bool isFormula() const;

private:
    string value;   // Raw value of the cell (could be a number, string, etc.)
    string formula; // Formula associated with the cell (if any)
};

#endif
