#include "SpreadsheetApp.h"
#include "AnsiTerminal.h"
#include <iostream>
#include <stdexcept> // For std::invalid_argument
using namespace std;
using namespace Spreadsheet;

int main()
{
    int rows = 10; // Desired number of rows
    int cols = 10; // Desired number of columns

    while (1)
    {
        try
        {
            cout << "Enter row and column:" << endl;
            cin >> rows;
            cin >> cols;

            // Check for invalid input
            if (rows <= 0 || cols <= 0)
            {
                throw invalid_argument("Rows and columns must be positive integers.");
            }

            // Exit the loop if inputs are valid
            break;
        }
        catch (const invalid_argument &e)
        {
            // Print the error message and prompt the user again
            cout << "Invalid input! " << e.what() << endl;
        }
    }

    // Create and run the SpreadsheetApp object
    SpreadsheetApp app(rows, cols); // Create the spreadsheet application with the specified rows and columns
    app.run();                      // Start the application

    return 0;
}
