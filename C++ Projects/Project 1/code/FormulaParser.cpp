#include "FormulaParser.h"
#include "Table.h"
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;

// Constructor to initialize the FormulaParser with a reference to the table
FormulaParser::FormulaParser(const Table &table) : table(table) {}

// Method to evaluate a formula passed as a string
double FormulaParser::evaluateFormula(const string &formula) const
{
    // Ensure the formula starts with '='
    if (formula.empty() || formula[0] != '=')
        throw invalid_argument("Formula must start with '='");

    istringstream ss(formula.substr(1)); // Skip the '=' character
    double result = 0.0;
    char op = '+'; // Default operator (addition)

    while (ss)
    {
        string token;
        ss >> token;

        if (token == "+" || token == "-")
        {
            // If token is '+' or '-', update the operator for the next number
            op = token[0];
        }
        else if (token == "*" || token == "/")
        {
            // Handle '*' and '/' operators with higher precedence
            char nextOp = token[0];
            double nextValue = 0.0;
            ss >> token; // Get the next token (could be a number or cell reference)

            // If the token is a cell reference (like A1), get its numeric value
            if (isalpha(token[0]))
            {
                int row = token[1] - '1';
                int col = token[0] - 'A';
                nextValue = table.getCellNumericValue(row, col);
            }
            else // If the token is a number, convert it to a double
            {
                nextValue = stod(token);
            }

            // Perform the multiplication or division based on the operator
            if (nextOp == '*')
                result *= nextValue;
            else if (nextOp == '/')
                result /= nextValue;
        }
        else if (isalpha(token[0])) // Cell reference or function
        {
            // Handle range functions (e.g., SUM(A1..A5))
            if (token.find("..") != string::npos)
            {
                string func = token.substr(0, token.find('('));
                string range = token.substr(func.size() + 1, token.size() - func.size() - 2);
                auto values = getRangeValues(range); // Get the values in the specified range

                double funcResult = 0.0;
                // Perform the corresponding function on the values
                if (func == "SUM")
                {
                    for (double v : values)
                        funcResult += v;
                }
                else if (func == "AVER")
                {
                    for (double v : values)
                        funcResult += v;
                    funcResult /= values.size();
                }
                else if (func == "STDDEV")
                {
                    double mean = 0.0;
                    for (double v : values)
                        mean += v;
                    mean /= values.size();
                    double variance = 0.0;
                    for (double v : values)
                        variance += (v - mean) * (v - mean);
                    funcResult = sqrt(variance / values.size());
                }
                else if (func == "MAX")
                {
                    funcResult = values[0];
                    for (double v : values)
                        if (v > funcResult)
                            funcResult = v;
                }
                else if (func == "MIN")
                {
                    funcResult = values[0];
                    for (double v : values)
                        if (v < funcResult)
                            funcResult = v;
                }

                // Apply the operator before the function result
                if (op == '+')
                    result += funcResult;
                else if (op == '-')
                    result -= funcResult;
                else if (op == '*')
                    result *= funcResult;
                else if (op == '/')
                    result /= funcResult;
            }
            else // Single cell reference
            {
                int row = token[1] - '1';
                int col = token[0] - 'A';
                double cellValue = table.getCellNumericValue(row, col);

                // Apply the operator to the cell value
                if (op == '+')
                    result += cellValue;
                else if (op == '-')
                    result -= cellValue;
                else if (op == '*')
                    result *= cellValue;
                else if (op == '/')
                    result /= cellValue;
            }
        }
        else if (isdigit(token[0]) || token[0] == '-' || token[0] == '.') // If token is a number
        {
            double value = stod(token);
            // Apply the operator to the number
            if (op == '+')
                result += value;
            else if (op == '-')
                result -= value;
            else if (op == '*')
                result *= value;
            else if (op == '/')
                result /= value;
        }
    }

    return result; // Return the final result after processing the formula
}

// Helper function to extract the values from a range (e.g., A1..A5)
vector<double> FormulaParser::getRangeValues(const string &range) const
{
    vector<double> values;
    size_t sep = range.find("..");
    if (sep == string::npos)
        throw invalid_argument("Invalid range format");

    string start = range.substr(0, sep);
    string end = range.substr(sep + 2);

    int startRow = start[1] - '1';
    int startCol = start[0] - 'A';
    int endRow = end[1] - '1';
    int endCol = end[0] - 'A';

    // Loop through the range and collect the values from the cells
    for (int r = startRow; r <= endRow; ++r)
    {
        for (int c = startCol; c <= endCol; ++c)
        {
            values.push_back(table.getCellNumericValue(r, c)); // Get numeric value of the cell
        }
    }
    return values;
}
