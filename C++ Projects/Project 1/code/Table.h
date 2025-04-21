#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>
#include "Cell.h"          // Cell class for individual cell data
#include "FormulaParser.h" // FormulaParser for evaluating formulas
using namespace std;
class Table
{
public:
    // Constructor to initialize the table with given rows and columns
    Table(int rows, int cols);

    // Getter for number of rows
    int getRows() const;

    // Getter for number of columns
    int getCols() const;

    // Get the value of a cell as a string
    string getCellValue(int row, int col) const;

    // Set the value of a cell, if it's a formula, it's handled accordingly
    void setCellValue(int row, int col, const string &value);

    // Get the formula of a cell
    string getCellFormula(int row, int col) const;

    // Set the formula of a cell
    void setCellFormula(int row, int col, const string &formula);

    // Get the numeric value of a cell (useful for calculations)
    double getCellNumericValue(int row, int col) const;

    // Navigation logic: move the current cell in the specified direction
    void navigate(char direction);

    // Update all formulas in the table using the FormulaParser
    void updateFormulas(const FormulaParser &formulaParser);

    // Get the current row index
    int getCurrentRow() const;

    // Get the current column index
    int getCurrentCol() const;

    // Set the current cell by row and column
    void setCurrentCell(int row, int col);

    // Get the address (label) of the current cell (e.g., "A1", "B2")
    string getCell() const;

private:
    // 2D vector of Cell objects representing the table's cells
    vector<vector<Cell>> cells;

    // Current row and column for navigation
    int currentRow;
    int currentCol;

    // Instance of FormulaParser to handle formula evaluation
    FormulaParser formulaParser;
};

#endif // TABLE_H
