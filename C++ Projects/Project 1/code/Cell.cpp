#include "Cell.h"
#include <sstream>
#include "Table.h"
#include <iostream>
using namespace std;
// Default constructor
Cell::Cell() : value(""), formula("") {}

// Set a value for the cell
void Cell::setValue(const string &value)
{
    this->value = value;
    // Clear the formula when a new value is assigned
}

// Set a new value for the cell, clearing the formula
void Cell::setNewValue(const string &value)
{
    this->value = value;
    formula.clear(); // Clear the formula when a new value is assigned
}

// Return the cell's value as a string
string Cell::getStringValue() const
{
    return value;
}

// Return the cell's value as a double (numeric)
double Cell::getDoubleValue() const
{
    try
    {
        return stod(value); // Convert the value to a number
    }
    catch (const invalid_argument &)
    {
        return 0.0; // Return 0 if the value is not a valid number
    }
}

// Get the formula of the cell
string Cell::getFormula() const
{
    return formula;
}

// Set a formula for the cell
void Cell::setFormula(const string &formula)
{
    this->formula = formula;
}

// Check if the cell's value is a number
bool Cell::isNumber() const
{
    istringstream iss(value);
    double num;
    return (iss >> num) && iss.eof(); // Check if the entire string is a valid number
}

// Check if the cell's value is a string (non-numeric and no formula)
bool Cell::isString() const
{
    return !isNumber() && formula.empty(); // Check if it's not a number and has no formula
}

// Check if the cell's value is a formula
bool Cell::isFormula() const
{
    return !formula.empty(); // A non-empty formula indicates it's a formula
}
