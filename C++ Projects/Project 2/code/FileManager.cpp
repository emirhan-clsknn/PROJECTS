// FileManager.cpp
#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;

// Save the table to a CSV file
bool FileManager::saveToCSV(const Table &table, const string &filename)
{
    ofstream outFile(filename);
    if (!outFile.is_open())
    {
        // Throw an exception if the file cannot be opened
        throw runtime_error("Failed to open file for saving: " + filename);
    }

    for (int row = 0; row < table.getRows(); ++row)
    {
        for (int col = 0; col < table.getCols(); ++col)
        {
            string formula = table.getCellFormula(row, col);
            if (!formula.empty() && formula[0] == '=')
            {
                outFile << formula; // Write the formula
            }
            else
            {
                outFile << table.getCellValue(row, col); // Write the cell value
            }

            if (col < table.getCols() - 1)
            {
                outFile << ","; // Add a comma between values
            }
        }
        outFile << "\n"; // Move to the next row
    }

    outFile.close(); // Close the file after saving
    return true;     // Indicate success
}

bool FileManager::loadFromCSV(Table &table, const string &filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open())
    {
        // Throw an exception if the file cannot be opened
        throw runtime_error("Failed to open file for loading: " + filename);
    }

    string line;
    int row = 0;

    while (getline(inFile, line))
    {
        stringstream ss(line);
        string cell;
        int col = 0;

        while (getline(ss, cell, ','))
        {
            // If the cell contains a formula, set it
            if (!cell.empty() && cell[0] == '=')
            {
                table.setCellFormula(row, col, cell);
            }
            else
            {
                table.setCellValue(row, col, cell); // Otherwise, set the cell value
            }

            col++; // Move to the next column
        }
        row++; // Move to the next row
    }

    inFile.close(); // Close the file after loading
    return true;    // Indicate success
}

// Make a new file (clear the current table)
void FileManager::makeNewFile(Table &table)
{
    int rows = table.getRows(); // Get the number of rows in the table
    int cols = table.getCols(); // Get the number of columns in the table

    // Clear all the cells in the table
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            table.setCellValue(row, col, ""); // Set each cell to an empty string
        }
    }
}

// Save the current file with a different name (Save As functionality)
void FileManager::saveAs(const Table &table, const string &filename)
{
    // Reuse the saveToCSV method to save the table with a new filename
    saveToCSV(table, filename);
}
