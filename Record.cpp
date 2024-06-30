
#include "Record.hpp"

Record::Record(Type type, double amount, const std::string& date, const std::string& category, const std::string& description)
    : type(type), amount(amount), date(date), category(category), description(description) {}

Record::Type Record::getType() const { return type; }
double Record::getAmount() const { return amount; }
std::string Record::getDate() const { return date; }
std::string Record::getCategory() const { return category; }
std::string Record::getDescription() const { return description; }

void Record::setType(Type type) { this->type = type; }
void Record::setAmount(double amount) { this->amount = amount; }
void Record::setDate(const std::string& date) { this->date = date; }
void Record::setCategory(const std::string& category) { this->category = category; }
void Record::setDescription(const std::string& description) { this->description = description; }
