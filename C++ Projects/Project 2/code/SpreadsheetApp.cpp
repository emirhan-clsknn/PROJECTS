#include "SpreadsheetApp.h"
#include "AnsiTerminal.h"
#include <iostream>
#include "FormulaParser.h"
#include "FileManager.h"
#include <string>
using namespace std;

// Constructor: Initialize table, terminal, and setup app state
namespace Spreadsheet
{
    // Constructor initializes the table, formula parser, and app state
    SpreadsheetApp::SpreadsheetApp(int rows, int cols)
        : table(rows, cols), formulaParser(table), isRunning(true)
    {
        this->currentFile = "spreadsheet.csv";
        if (!currentFile.empty())
        {
            loadFile(currentFile); // Load file if a file name is provided
        }
    }

    // Destructor: Ensure file is saved and terminal is cleared when the app is closed
    SpreadsheetApp::~SpreadsheetApp()
    {
        // Save the file if it's not empty
        if (!currentFile.empty())
        {
            saveFile();
        }
        terminal.clearScreen();
        terminal.printAt(1, 1, "Exiting application... Goodbye!"); // Display exit message
    }

    // Save the table to the current file
    void SpreadsheetApp::saveFile()
    {
        if (currentFile.empty())
        {
            std::cout << "No file specified for saving.\n"; // Print message if no file is specified
            return;
        }

        if (!fileManager.saveToCSV(table, currentFile))
        {
            std::cerr << "Failed to save file.\n"; // Print error message if saving fails
            return;
        }

        std::cout << "File saved successfully.\n"; // Success message on saving
    }

    // Load the table from the specified CSV file
    void SpreadsheetApp::loadFile(const std::string &filename)
    {
        if (!fileManager.loadFromCSV(table, filename))
        {
            std::cerr << "Failed to load file.\n"; // Print error message if loading fails
            return;
        }

        currentFile = filename;                     // Set the current file after successful load
        std::cout << "File loaded successfully.\n"; // Success message on loading
    }

    // Main loop of the application
    void SpreadsheetApp::run()
    {
        terminal.clearScreen(); // Clear the terminal screen
        while (isRunning)       // Run the application until the user decides to quit
        {
            terminal.clearScreen();
            table.updateFormulas(formulaParser); // Update cell formulas using FormulaParser
            displayTable();                      // Display table contents
            processInput();                      // Process user input (navigation, editing, etc.)
        }
    }

    // Get column label (A, B, C... Z, AA, AB...)
    std::string getColumnLabel(int col)
    {
        std::string label = "";
        while (col >= 0)
        {
            label = char('A' + col % 26) + label; // Get the letter for the current column
            col = col / 26 - 1;                   // Move to the next letter (e.g., A -> B, Z -> AA)
        }
        return label;
    }

    // Display the table on the terminal
    void SpreadsheetApp::displayTable()
    {
        // Print column headers
        terminal.printAt(1, 0, table.getCell());
        terminal.printAt(1, 10, table.getCellValue(table.getCurrentRow(), table.getCurrentCol()));
        for (int col = 0; col < table.getCols(); ++col)
        {
            std::string colLabel = getColumnLabel(col); // Get the column label (A, B, ..., Z, AA, AB, ...)
            terminal.printAt(3, 5 + col * 8, colLabel); // Print each column label
        }

        // Print each row with its row number and values
        for (int row = 0; row < table.getRows(); ++row)
        {
            terminal.printAt(5 + row * 2, 2, std::to_string(row + 1)); // Row number
            for (int col = 0; col < table.getCols(); ++col)
            {
                std::string value = table.getCellValue(row, col);               // Get the value of the cell
                terminal.printAt(5 + row * 2, 5 + col * 8, value.substr(0, 5)); // Print cell value (first 5 characters)
            }
        }

        // Highlight the current cell
        terminal.printInvertedAt(5 + table.getCurrentRow() * 2, 5 + table.getCurrentCol() * 8,
                                 table.getCellValue(table.getCurrentRow(), table.getCurrentCol())); // Highlight current cell
    }

    // Process user input for cell navigation, editing, etc.
    void SpreadsheetApp::processInput()
    {
        char input = terminal.getSpecialKey(); // Get the user's input

        switch (input)
        {
        case 'U':
        case 'u':
            table.navigate('U'); // Move up
            break;
        case 'D':
        case 'd':
            table.navigate('D'); // Move down
            break;
        case 'L':
        case 'l':
            table.navigate('L'); // Move left
            break;
        case 'R':
        case 'r':
            table.navigate('R'); // Move right
            break;
        case 'E': // Enter edit mode (Linux/macOS)
        case 'e': // Enter edit mode (Windows)
            editCell();
            break;
        case 'Q':
        case 'q':
            isRunning = false; // Quit the application
            break;
            // Additional controls can be added here
        }
    }

    // Enter edit mode to modify the current cell's value
    void SpreadsheetApp::editCell()
    {
        terminal.printAt(1, 1, "Enter new value: ");
        std::string newValue;
        char ch;

        // Allow user to type characters and immediately display them
        while (true)
        {
            ch = std::cin.get(); // Read a character

            // Complete input when Enter is pressed
            if (ch == '\n')
            {
                break;
            }
            // Handle Backspace
            else if (ch == '\b' || ch == 127)
            {
                if (!newValue.empty())
                {
                    // Remove last character
                    newValue.pop_back();

                    // Erase the character from the terminal by moving the cursor back and writing a space
                    int cursorPos = 18 + newValue.size(); // 1st row, 2nd column
                    terminal.printAt(1, cursorPos, " ");
                    terminal.printAt(1, cursorPos, ""); // Move cursor to the correct position
                }
            }
            // Handle normal characters
            else
            {
                newValue += ch;
                terminal.printAt(1, 18 + newValue.size() - 1, std::string(1, ch));
            }
        }

        // Update the cell value
        table.setCellValue(table.getCurrentRow(), table.getCurrentCol(), newValue);
    }
};
