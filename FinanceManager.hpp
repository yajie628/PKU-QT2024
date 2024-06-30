#ifndef FINANCEMANAGER_HPP
#define FINANCEMANAGER_HPP

#include "Record.hpp"
#include <vector>
#include <string>

class FinanceManager {
public:
    void addRecord(const Record& record);
    void editRecord(int index, const Record& record);
    void deleteRecord(int index);
    std::vector<Record> getRecords() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<Record> records;
};

#endif // FINANCEMANAGER_HPP
