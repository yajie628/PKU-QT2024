#ifndef RECORD_HPP
#define RECORD_HPP

#include <string>

class Record {
public:
    enum Type { INCOME, EXPENSE };

    Record(Type type, double amount, const std::string& date, const std::string& category, const std::string& description);

    Type getType() const;
    double getAmount() const;
    std::string getDate() const;
    std::string getCategory() const;
    std::string getDescription() const;

    void setType(Type type);
    void setAmount(double amount);
    void setDate(const std::string& date);
    void setCategory(const std::string& category);
    void setDescription(const std::string& description);

private:
    Type type;
    double amount;
    std::string date;
    std::string category;
    std::string description;
};

#endif // RECORD_HPP
