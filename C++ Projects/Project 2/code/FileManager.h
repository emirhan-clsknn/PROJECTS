#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "Table.h"
using namespace std;

// FileManager class provides static methods for file operations on a table
class FileManager
{
public:
    // Constructor and Destructor
    FileManager() = default; // Default constructor, no special initialization needed

    // Save the table to a CSV file
    // Throws std::runtime_error if the file cannot be opened or saved
    static bool saveToCSV(const Table &table, const string &filename);

    // Load a table from a CSV file
    // Throws std::runtime_error if the file cannot be opened or loaded
    static bool loadFromCSV(Table &table, const string &filename);

    // Make a new file (this will typically clear the current table)
    // Resets all cells in the table to empty values
    static void makeNewFile(Table &table);

    // Save the current file with a different name (Save As functionality)
    // Internally reuses saveToCSV for implementation
    static void saveAs(const Table &table, const string &filename);
};

#endif
