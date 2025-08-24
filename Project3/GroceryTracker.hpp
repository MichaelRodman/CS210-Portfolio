/*
 * Michael Rodman
 * 2025-08-16
 * Description: Defines the GroceryTracker class to load, count, and display
 * item frequencies from Corner Grocer input files.
 */

#ifndef GROCERYTRACKER_HPP
#define GROCERYTRACKER_HPP

#include <map>
#include <string>

 /**
 This class will manage grocery item frequencies and provide functionality to
 query, display, and back up the results.
 Parameter none
 Return none
 */
class GroceryTracker {
public:
    /**
    This method will load grocery item data from the given input file and count frequencies.
    Parameter inputFile - const std::string& - path to the text input file
    Return true if file is opened and processed successfully, otherwise false - bool
    */
    bool LoadData(const std::string& inputFile);

    /**
    This method will write all frequencies to the backup file (frequency.dat).
    Parameter backupFile - const std::string& - path to the backup file
    Return true if file is created and written successfully, otherwise false - bool
    */
    bool WriteBackup(const std::string& backupFile) const;

    /**
    This method will return the frequency of a given item.
    Parameter item - const std::string& - grocery item to look up
    Return frequency count (0 if not found) - int
    */
    int GetFrequency(const std::string& item) const;

    /**
    This method will print all items and their frequencies to standard output.
    Parameter none
    Return nothing - void
    */
    void PrintAllFrequencies() const;

    /**
    This method will print a histogram using asterisks for each item's frequency.
    Parameter none
    Return nothing - void
    */
    void PrintHistogram() const;

private:
    std::map<std::string, int> frequencyMap;
};

#endif

