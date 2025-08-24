/*
 * Michael Rodman
 * 2025-08-16
 * Description: Menu-driven program for Corner Grocer to analyze item frequencies.
 */

#include <iostream>
#include "GroceryTracker.hpp"

 /**
 This method will display the user menu and get a selection.
 Parameter none
 Return menu option selected - int
 */
int DisplayMenu() {
    std::cout << "\n===== Corner Grocer Menu =====\n";
    std::cout << "1) Find frequency of an item\n";
    std::cout << "2) Print all item frequencies\n";
    std::cout << "3) Print histogram of item frequencies\n";
    std::cout << "4) Exit\n";
    std::cout << "Enter option: ";

    int choice;
    std::cin >> choice;
    return choice;
}

int main() {
    GroceryTracker tracker;
    std::string inputFile = "CS210_Project_Three_Input_File.txt";
    std::string backupFile = "frequency.dat";

    if (!tracker.LoadData(inputFile)) {
        std::cout << "Error: Unable to open input file.\n";
        return 1;
    }

    // Create backup at start
    tracker.WriteBackup(backupFile);

    bool running = true;
    while (running) {
        int choice = DisplayMenu();

        switch (choice) {
        case 1: {
            std::string item;
            std::cout << "Enter item name: ";
            std::cin >> item;
            int freq = tracker.GetFrequency(item);
            std::cout << item << " " << freq << std::endl;
            break;
        }
        case 2:
            tracker.PrintAllFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            running = false;
            break;
        default:
            std::cout << "Invalid option. Try again.\n";
        }
    }

    std::cout << "Exiting Corner Grocer program.\n";
    return 0;
}