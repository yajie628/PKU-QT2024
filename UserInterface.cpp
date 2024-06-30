#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

// Record.hpp and Record.cpp content
class Record {
public:
    enum Type { INCOME, EXPENSE };

    Record(Type type, double amount, const std::string& date, const std::string& category, const std::string& description)
        : type(type), amount(amount), date(date), category(category), description(description) {}

    Type getType() const { return type; }
    double getAmount() const { return amount; }
    std::string getDate() const { return date; }
    std::string getCategory() const { return category; }
    std::string getDescription() const { return description; }

    void setType(Type type) { this->type = type; }
    void setAmount(double amount) { this->amount = amount; }
    void setDate(const std::string& date) { this->date = date; }
    void setCategory(const std::string& category) { this->category = category; }
    void setDescription(const std::string& description) { this->description = description; }

private:
    Type type;
    double amount;
    std::string date;
    std::string category;
    std::string description;
};

// FinanceManager.hpp and FinanceManager.cpp content
class FinanceManager {
public:
    void addRecord(const Record& record) { records.push_back(record); }
    void editRecord(int index, const Record& record) {
        if (index < 0 || index >= records.size()) {
            throw std::out_of_range("Index out of range");
        }
        records[index] = record;
    }
    void deleteRecord(int index) {
        if (index < 0 || index >= records.size()) {
            throw std::out_of_range("Index out of range");
        }
        records.erase(records.begin() + index);
    }
    std::vector<Record> getRecords() const { return records; }
    void saveToFile(const std::string& filename) const {
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
    void loadFromFile(const std::string& filename) {
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

private:
    std::vector<Record> records;
};

// Report.hpp and Report.cpp content
class Report {
public:
    static void generateMonthlyReport(const std::vector<Record>& records, const std::string& month) {
        double income = 0.0;
        double expense = 0.0;
        for (const auto& record : records) {
            if (record.getDate().substr(0, 7) == month) {
                if (record.getType() == Record::INCOME) {
                    income += record.getAmount();
                } else {
                    expense += record.getAmount();
                }
            }
        }
        std::cout << "Monthly Report for " << month << "\n";
        std::cout << "Total Income: " << income << "\n";
        std::cout << "Total Expense: " << expense << "\n";
    }

    static void generateAnnualReport(const std::vector<Record>& records, const std::string& year) {
        double income = 0.0;
        double expense = 0.0;
        for (const auto& record : records) {
            if (record.getDate().substr(0, 4) == year) {
                if (record.getType() == Record::INCOME) {
                    income += record.getAmount();
                } else {
                    expense += record.getAmount();
                }
            }
        }
        std::cout << "Annual Report for " << year << "\n";
        std::cout << "Total Income: " << income << "\n";
        std::cout << "Total Expense: " << expense << "\n";
    }

    static void generateCategoryReport(const std::vector<Record>& records, const std::string& category) {
        double total = 0.0;
        for (const auto& record : records) {
            if (record.getCategory() == category) {
                total += record.getAmount();
            }
        }
        std::cout << "Category Report for " << category << "\n";
        std::cout << "Total Amount: " << total << "\n";
    }
};

// UserInterface.hpp and UserInterface.cpp content
class UserInterface {
public:
    void run() {
        bool exit = false;
        while (!exit) {
            displayMenu();
            int choice;
            std::cin >> choice;
            switch (choice) {
                case 1:
                    handleAddRecord();
                    break;
                case 2:
                    handleEditRecord();
                    break;
                case 3:
                    handleDeleteRecord();
                    break;
                case 4:
                    handleViewRecords();
                    break;
                case 5:
                    handleGenerateReport();
                    break;
                case 6:
                    handleSaveToFile();
                    break;
                case 7:
                    handleLoadFromFile();
                    break;
                case 0:
                    exit = true;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        }
    }

private:
    FinanceManager financeManager;

    void displayMenu() const {
        std::cout << "1. Add Record\n";
        std::cout << "2. Edit Record\n";
        std::cout << "3. Delete Record\n";
        std::cout << "4. View Records\n";
        std::cout << "5. Generate Report\n";
        std::cout << "6. Save to File\n";
        std::cout << "7. Load from File\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
    }

    void handleAddRecord() {
        int type;
        double amount;
        std::string date, category, description;
        std::cout << "Enter type (0 for INCOME, 1 for EXPENSE): ";
        std::cin >> type;
        std::cout << "Enter amount: ";
        std::cin >> amount;
        std::cout << "Enter date (YYYY-MM-DD): ";
        std::cin >> date;
        std::cout << "Enter category: ";
        std::cin >> category;
        std::cout << "Enter description: ";
        std::cin >> description;
        financeManager.addRecord(Record(static_cast<Record::Type>(type), amount, date, category, description));
    }

    void handleEditRecord() {
        int index;
        std::cout << "Enter record index to edit: ";
        std::cin >> index;
        int type;
        double amount;
        std::string date, category, description;
        std::cout << "Enter new type (0 for INCOME, 1 for EXPENSE): ";
        std::cin >> type;
        std::cout << "Enter new amount: ";
        std::cin >> amount;
        std::cout << "Enter new date (YYYY-MM-DD): ";
        std::cin >> date;
        std::cout << "Enter new category: ";
        std::cin >> category;
        std::cout << "Enter new description: ";
        std::cin >> description;
        financeManager.editRecord(index, Record(static_cast<Record::Type>(type), amount, date, category, description));
    }

    void handleDeleteRecord() {
        int index;
        std::cout << "Enter record index to delete: ";
        std::cin >> index;
        financeManager.deleteRecord(index);
    }

    void handleViewRecords() const {
        auto records = financeManager.getRecords();
        for (size_t i = 0; i < records.size(); ++i) {
            std::cout << i << ": "
                      << (records[i].getType() == Record::INCOME ? "INCOME" : "EXPENSE") << " "
                      << records[i].getAmount() << " "
                      << records[i].getDate() << " "
                      << records[i].getCategory() << " "
                      << records[i].getDescription() << "\n";
        }
    }

    void handleGenerateReport() const {
        int choice;
        std::cout << "1. Monthly Report\n";
        std::cout << "2. Annual Report\n";
        std::cout << "3. Category Report\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::string param;
        std::cin.ignore();  // Ignore any newline character left in the input buffer
        if (choice == 1) {
            std::cout << "Enter month (YYYY-MM): ";
            std::getline(std::cin, param);  // Use getline to read the input
            Report::generateMonthlyReport(financeManager.getRecords(), param);
        } else if (choice == 2) {
            std::cout << "Enter year (YYYY): ";
            std::getline(std::cin, param);  // Use getline to read the input
            Report::generateAnnualReport(financeManager.getRecords(), param);
        } else if (choice == 3) {
            std::cout << "Enter category: ";
            std::getline(std::cin, param);  // Use getline to read the input
            Report::generateCategoryReport(financeManager.getRecords(), param);
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    void handleSaveToFile() const {
        std::string filename;
        std::cout << "Enter filename to save: ";
        std::cin >> filename;
        financeManager.saveToFile(filename);
    }

    void handleLoadFromFile() {
        std::string filename;
        std::cout << "Enter filename to load: ";
        std::cin >> filename;
        financeManager.loadFromFile(filename);
    }
};

// main.cpp content
int main() {
    UserInterface ui;
    ui.run();
    return 0;
}
