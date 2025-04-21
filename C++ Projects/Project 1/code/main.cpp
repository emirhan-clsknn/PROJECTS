#include "SpreadsheetApp.h"
#include "AnsiTerminal.h"
#include <iostream>

int main()
{
    int rows = 10; // Desired number of rows     !!!!!!PLEASE DON'T FORGET CHANGE ROW AND COL IN MAIN.CPP WHEN YOU ENTER A NEW CSV.!!!!!!
    int cols = 10; // Desired number of columns   !!!!!!PLEASE DON'T FORGET CHANGE ROW AND COL IN MAIN.CPP WHEN YOU ENTER A NEW CSV.!!!!!!

    // Create and run the SpreadsheetApp object
    SpreadsheetApp app(rows, cols);
    app.run();

    return 0;
}
