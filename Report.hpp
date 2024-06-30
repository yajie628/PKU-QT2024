#ifndef REPORT_HPP
#define REPORT_HPP

#include "Record.hpp"
#include <vector>
#include <string>

class Report {
public:
    static void generateMonthlyReport(const std::vector<Record>& records, const std::string& month);
    static void generateAnnualReport(const std::vector<Record>& records, const std::string& year);
    static void generateCategoryReport(const std::vector<Record>& records, const std::string& category);
};

#endif // REPORT_HPP
