/*
 * Michael Rodman
 * 2025-08-16
 * Description: Implements the GroceryTracker class.
 */

#include "GroceryTracker.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

bool GroceryTracker::LoadData(const std::string& inputFile) {
    std::ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        return false;
    }

    std::string item;
    while (inFile >> item) {
        frequencyMap[item]++;
    }
    inFile.close();
    return true;
}

bool GroceryTracker::WriteBackup(const std::string& backupFile) const {
    std::ofstream outFile(backupFile);
    if (!outFile.is_open()) {
        return false;
    }

    for (const auto& pair : frequencyMap) {
        outFile << pair.first << " " << pair.second << std::endl;
    }
    outFile.close();
    return true;
}

int GroceryTracker::GetFrequency(const std::string& item) const {
    auto it = frequencyMap.find(item);
    if (it != frequencyMap.end()) {
        return it->second;
    }
    return 0;
}

void GroceryTracker::PrintAllFrequencies() const {
    for (const auto& pair : frequencyMap) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

void GroceryTracker::PrintHistogram() const {
    for (const auto& pair : frequencyMap) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
