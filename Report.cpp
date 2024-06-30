#include "Report.hpp"
#include <iostream>
#include <map>

void Report::generateMonthlyReport(const std::vector<Record>& records, const std::string& month) {
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

void Report::generateAnnualReport(const std::vector<Record>& records, const std::string& year) {
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

void Report::generateCategoryReport(const std::vector<Record>& records, const std::string& category) {
    double total = 0.0;
    for (const auto& record : records) {
        if (record.getCategory() == category) {
            total += record.getAmount();
        }
    }
    std::cout << "Category Report for " << category << "\n";
    std::cout << "Total Amount: " << total << "\n";
}
