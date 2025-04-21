// FileManager.h
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "Table.h"
using namespace std;
class FileManager
{
public:
    // Constructor and Destructor
    FileManager() = default; // Default constructor, no special initialization needed

    // Save the table to a CSV file
    static bool saveToCSV(const Table &table, const string &filename);

    // Load a table from a CSV file
    static bool loadFromCSV(Table &table, const string &filename);

    // Make a new file (this will typically clear the current table)
    static void makeNewFile(Table &table);

    // Save the current file with a different name (Save As functionality)
    static void saveAs(const Table &table, const string &filename);
};

#endif
