#include "Table.h"
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <sstream>
#include "ValueCell.h"
#include "DoubleValueCell.h"
#include "FormulaCell.h"
#include "IntValueCell.h"
#include "DoubleValueCell.h"
#include "StringValueCell.h"
#include "Cell.h"
using namespace std;
using namespace Cells;
// Constructor: Initialize the table with rows and columns

Table::Table(int rows, int cols)
    : cells(rows), currentRow(0), currentCol(0), formulaParser(*this)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cells[i].push_back(make_unique<ValueCell>());
        }
    }
}

// Get the number of rows in the table
int Table::getRows() const
{
    return cells.get_size();
}

// Get the number of columns in the table
int Table::getCols() const
{
    return cells.empty() ? 0 : cells[0].get_size();
}

// Get or set cell value
string Table::getCellValue(int row, int col) const
{
    if (row < 0 || row >= getRows() || col < 0 || col >= getCols())
    {
        throw out_of_range("Cell index out of range");
    }
    if (cells[row][col]->isFormula())
    {
        return to_string(cells[row][col]->getDoubleValue());
    }
    return cells[row][col]->getStringValue();
}

void Table::setCellValue(int row, int col, const string &value)
{
    if (row < 0 || row >= getRows() || col < 0 || col >= getCols())
    {
        throw out_of_range("Cell index out of range");
    }
    if (value[0] == '=') // Detect formula
    {
        cells[row][col] = move(make_unique<FormulaCell>(value));
        return;
    }
    stringstream ss(value);
    int intVal;
    double doubleVal;

    // Integer kontrolü
    if (ss >> intVal && ss.eof())
    {
        cells[row][col] = move(make_unique<IntValueCell>(value));
    }

    // Double kontrolü
    ss.clear();    // Stringstream'i temizle
    ss.str(value); // Aynı input'u tekrar kullan
    if (ss >> doubleVal && ss.eof())
    {
        cells[row][col] = move(make_unique<DoubleValueCell>(value));
    }
    cells[row][col] = move(make_unique<StringValueCell>(value));
}

// Set or get cell formula
string Table::getCellFormula(int row, int col) const
{
    if (row < 0 || row >= getRows() || col < 0 || col >= getCols())
    {
        throw out_of_range("Cell index out of range");
    }
    if (cells[row][col]->isFormula())
    {
        return cells[row][col]->getStringValue();
    }
    return "";
}

void Table::setCellFormula(int row, int col, const string &formula)
{
    if (row < 0 || row >= getRows() || col < 0 || col >= getCols())
    {
        throw out_of_range("Cell index out of range");
    }
    cells[row][col] = move(make_unique<FormulaCell>(formula, ""));
}

// Get numeric value of a cell for calculations
double Table::getCellNumericValue(int row, int col) const
{
    if (row < 0 || row >= getRows() || col < 0 || col >= getCols())
    {
        throw out_of_range("Cell index out of range");
    }
    return cells[row][col]->getDoubleValue();
}

// Navigation logic for moving between cells
void Table::navigate(char direction)
{
    switch (direction)
    {
    case 'U': // Up
        if (currentRow > 0)
            --currentRow;
        break;
    case 'D': // Down
        if (currentRow < getRows() - 1)
            ++currentRow;
        break;
    case 'L': // Left
        if (currentCol > 0)
            --currentCol;
        break;
    case 'R': // Right
        if (currentCol < getCols() - 1)
            ++currentCol;
        break;
    default:
        cerr << "Invalid navigation direction!" << endl;
        break;
    }
}

// Formula evaluation now uses FormulaParser
void Table::updateFormulas(const FormulaParser &formulaParser)
{
    for (int row = 0; row < getRows(); ++row)
    {
        for (int col = 0; col < getCols(); ++col)
        {
            if (cells[row][col]->isFormula())
            {
                // Formula hücresini taşımak için move kullanılır
                cells[row][col] = move(make_unique<FormulaCell>(
                    cells[row][col]->getStringValue(),
                    to_string(formulaParser.evaluateFormula(cells[row][col]->getStringValue()))));
            }
        }
    }
}

// Current cell position
int Table::getCurrentRow() const { return currentRow; }
int Table::getCurrentCol() const { return currentCol; }

void Table::setCurrentCell(int row, int col)
{
    if (row < 0 || row >= getRows() || col < 0 || col >= getCols())
    {
        throw out_of_range("Invalid cell index");
    }
    currentRow = row;
    currentCol = col;
}

// Helper function to get the column label (e.g., A, B, C, ... AA, AB, ...)
string getColumnLabels(int col)
{
    string label = "";
    while (col >= 0)
    {
        label = char('A' + col % 26) + label; // Get the letter for the current place
        col = col / 26 - 1;                   // Move to the next letter (e.g., A -> B, Z -> AA)
    }
    return label;
}

// Get the current cell's address (e.g., A1, B2)
string Table::getCell() const
{
    string colLabel = getColumnLabels(currentCol); // Column label (A, B, C, ...)
    string rowLabel = to_string(currentRow + 1);   // Row label (1, 2, 3, ...)
    return colLabel + rowLabel;
}
