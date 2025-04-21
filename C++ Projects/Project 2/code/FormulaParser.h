#ifndef FORMULAPARSER_H
#define FORMULAPARSER_H

#include <string>
#include <vector>
using namespace std;

class Table; // Forward declaration of the Table class

class FormulaParser
{
public:
    // Constructor to associate the FormulaParser with a Table object
    FormulaParser(const Table &table);

    // Method to evaluate a formula string and return the result as a double
    double evaluateFormula(const string &formula) const;

    // Method to extract and return the numeric values from a cell range (e.g., "A1..A5")
    vector<double> getRangeValues(const string &range) const;

private:
    const Table &table; // Reference to the associated Table object, to access its cell values
};

#endif // FORMULAPARSER_H
