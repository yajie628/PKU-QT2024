#include "FinanceManager.hpp"
#include <fstream>
#include <stdexcept>

void FinanceManager::addRecord(const Record& record) {
    records.push_back(record);
}

void FinanceManager::editRecord(int index, const Record& record) {
    if (index < 0 || index >= records.size()) {
        throw std::out_of_range("Index out of range");
    }
    records[index] = record;
}

void FinanceManager::deleteRecord(int index) {
    if (index < 0 || index >= records.size()) {
        throw std::out_of_range("Index out of range");
    }
    records.erase(records.begin() + index);
}

std::vector<Record> FinanceManager::getRecords() const {
    return records;
}

void FinanceManager::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::runtime_error("Cannot open file for writing");
    }
    for (const auto& record : records) {
        outFile << record.getType() << " "
                << record.getAmount() << " "
                << record.getDate() << " "
                << record.getCategory() << " "
                << record.getDescription() << "\n";
    }
}

void FinanceManager::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        throw std::runtime_error("Cannot open file for reading");
    }
    records.clear();
    int type;
    double amount;
    std::string date, category, description;
    while (inFile >> type >> amount >> date >> category >> description) {
        records.emplace_back(static_cast<Record::Type>(type), amount, date, category, description);
    }
}
