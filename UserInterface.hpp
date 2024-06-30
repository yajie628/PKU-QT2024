#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "FinanceManager.hpp"

class UserInterface {
public:
    void run();

private:
    FinanceManager financeManager;

    void displayMenu() const;
    void handleAddRecord();
    void handleEditRecord();
    void handleDeleteRecord();
    void handleViewRecords() const;
    void handleGenerateReport() const;
    void handleSaveToFile() const;
    void handleLoadFromFile();
};

#endif // USERINTERFACE_HPP
