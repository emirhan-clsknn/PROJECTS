#include "SpreadsheetApp.h"
#include "AnsiTerminal.h"
#include <iostream>
#include "FormulaParser.h"
#include "FileManager.h"
#include <string>
using namespace std;
// Constructor: Initialize table, terminal, and setup app state
SpreadsheetApp::SpreadsheetApp(int rows, int cols)
    : table(rows, cols), formulaParser(table), isRunning(true)
{
    this->currentFile = "spreadsheet.csv";
    if (!currentFile.empty())
    {
        loadFile(currentFile);
    }
}
SpreadsheetApp::~SpreadsheetApp()
{
    // Program kapandığında dosyayı kaydet
    if (!currentFile.empty())
    {
        saveFile();
    }
    terminal.clearScreen();
    terminal.printAt(1, 1, "Exiting application... Goodbye!");
}
void SpreadsheetApp::saveFile()
{
    if (currentFile.empty())
    {
        std::cout << "No file specified for saving.\n";
        return;
    }

    if (!fileManager.saveToCSV(table, currentFile))
    {
        std::cerr << "Failed to save file.\n";
        return;
    }

    std::cout << "File saved successfully.\n";
}

void SpreadsheetApp::loadFile(const std::string &filename)
{
    if (!fileManager.loadFromCSV(table, filename))
    {
        std::cerr << "Failed to load file.\n";
        return;
    }

    currentFile = filename;
    std::cout << "File loaded successfully.\n";
}

// Main loop of the application
void SpreadsheetApp::run()
{
    terminal.clearScreen();
    while (isRunning)
    {
        terminal.clearScreen();
        table.updateFormulas(formulaParser); // Formula parsing through FormulaParser
        displayTable();                      // Display table contents
        processInput();                      // Process user input
    }
}

// Display the table in the terminal
void SpreadsheetApp::displayTable()
{
    // Print column headers
    terminal.printAt(1, 0, table.getCell());
    terminal.printAt(1, 10, table.getCellValue(table.getCurrentRow(), table.getCurrentCol()));
    for (int col = 0; col < table.getCols(); ++col)
    {
        char colLabel = 'A' + col;
        terminal.printAt(3, 5 + col * 8, std::string(1, colLabel));
    }

    // Print each row with its row label
    for (int row = 0; row < table.getRows(); ++row)
    {
        terminal.printAt(5 + row * 2, 2, std::to_string(row + 1)); // Row number
        for (int col = 0; col < table.getCols(); ++col)
        {
            std::string value = table.getCellValue(row, col);
            terminal.printAt(5 + row * 2, 5 + col * 8, value.substr(0, 5));
        }
    }

    // Highlight the current cell
    terminal.printInvertedAt(5 + table.getCurrentRow() * 2, 5 + table.getCurrentCol() * 8,
                             table.getCellValue(table.getCurrentRow(), table.getCurrentCol()));
}

// Process user input and handle cell navigation, editing, etc.
void SpreadsheetApp::processInput()
{
    char input = terminal.getSpecialKey();

    switch (input)
    {
    case 'U':
    case 'u':
        table.navigate('U');
        break; // Move up
    case 'D':
    case 'd':
        table.navigate('D');
        break; // Move down
    case 'L':
    case 'l':
        table.navigate('L');
        break; // Move left
    case 'R':
    case 'r':
        table.navigate('R');
        break; // Move right
    case 'E':  // Linux/macOS
    case 'e':  // Windows
        editCell();
        break; // Enter edit mode
    case 'Q':
    case 'q':
        isRunning = false;
        break; // Quit application
        // Additional controls can be added here
    }
}

// Enter edit mode to modify the current cell's value
void SpreadsheetApp::editCell()
{
    terminal.printAt(1, 1, "Enter new value: ");
    std::string newValue;
    char ch;

    // Kullanıcının yazdığı karakterleri anında ekrana basma
    while (true)
    {
        ch = std::cin.get(); // Karakter oku

        // Enter tuşu ile girişi tamamla
        if (ch == '\n')
        {
            break;
        }
        // Backspace kontrolü
        else if (ch == '\b' || ch == 127)
        {
            if (!newValue.empty())
            {
                // Son karakteri kaldır
                newValue.pop_back();

                // Terminalden silmek için önce kursörü geri alıp boşluk yaz
                int cursorPos = 18 + newValue.size(); // 1. satır, 2. sütundan başlar
                terminal.printAt(1, cursorPos, " ");
                terminal.printAt(1, cursorPos, ""); // Kursörü doğru yere taşı
            }
        }
        // Normal karakterler
        else
        {
            newValue += ch;
            terminal.printAt(1, 18 + newValue.size() - 1, std::string(1, ch));
        }
    }
    table.setCellValue(table.getCurrentRow(), table.getCurrentCol(), newValue);
}