#ifndef SPREADSHEETAPP_H
#define SPREADSHEETAPP_H

#include "Table.h"
#include "AnsiTerminal.h"
#include <string>
#include "FormulaParser.h"
#include "FileManager.h"
using namespace std;

// SpreadsheetApp class definition
class SpreadsheetApp
{
public:
    // Constructor: Initialize with the number of rows and columns
    SpreadsheetApp(int rows, int cols);

    // Run the application (main loop)
    void run();

    // Destructor: Clean up the terminal and finish
    ~SpreadsheetApp();

private:
    // Method to display the table on the screen
    void displayTable();

    // Method to save the current table to a file
    void saveFile();

    // Method to load a table from a specified file
    void loadFile(const string &filename);

    // Method to process user input (navigation, editing, etc.)
    void processInput();

    // Method to allow the user to edit the current cell
    void editCell();

    // Table of cells
    Table table;

    // Terminal utility for handling screen and input
    AnsiTerminal terminal;

    // Formula parser to evaluate formulas in the table
    FormulaParser formulaParser;

    // File manager for file operations (saving/loading)
    FileManager fileManager;

    // Flag to keep the application running
    bool isRunning;

    // Name of the current file (for saving/loading)
    string currentFile;
};

#endif // SPREADSHEETAPP_H
