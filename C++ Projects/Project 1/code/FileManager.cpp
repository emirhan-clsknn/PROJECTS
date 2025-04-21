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
        cerr << "Failed to open file for saving.\n";
        return false;
    }

    for (int row = 0; row < table.getRows(); ++row)
    {
        for (int col = 0; col < table.getCols(); ++col)
        {
            // Eğer hücrede formül varsa, formülü kaydet
            string formula = table.getCellFormula(row, col);
            if (!formula.empty() && formula[0] == '=')
            {
                outFile << formula; // Formülü yaz
            }
            else
            {
                outFile << table.getCellValue(row, col); // Değeri yaz
            }

            if (col < table.getCols() - 1)
            {
                outFile << ",";
            }
        }
        outFile << "\n";
    }

    outFile.close();
    return true;
}

bool FileManager::loadFromCSV(Table &table, const string &filename)
{
    ifstream inFile(filename);
    if (!inFile.is_open())
    {
        cerr << "Failed to open file for loading.\n";
        return false;
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
            // Eğer hücre bir formülse, formülü ayarla
            if (!cell.empty() && cell[0] == '=')
            {
                table.setCellFormula(row, col, cell);
            }
            else
            {
                table.setCellValue(row, col, cell);
            }

            col++;
        }
        row++;
    }

    inFile.close();
    return true;
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
    saveToCSV(table, filename); // Reuse the saveToCSV method to save the table with a new filename
}
