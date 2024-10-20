#include <iostream>
#include <string>

class bankAccount {
private:
    std::string accountHolderName;
    int accountNumber;
    std::string accountType;  
    double balance;
    double interestRate;  

    static int nextAccountNumber;  

public:
    bankAccount(std::string name, std::string type, double bal, double rate) {
        accountHolderName = name;
        accountNumber = ++nextAccountNumber;  
        accountType = type;
        balance = bal;
        interestRate = rate;
    }

    std::string getAccountHolderName() const {
        return accountHolderName;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    std::string getAccountType() const {
        return accountType;
    }

    double getBalance() const {
        return balance;
    }

    double getInterestRate() const {
        return interestRate;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void applyInterest() {
        balance += balance * interestRate;
    }

    void displayAccountInfo() const {
        std::cout << "Account Holder: " << accountHolderName << "\n";
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Account Type: " << accountType << "\n";
        std::cout << "Balance: $" << balance << "\n";
        std::cout << "Interest Rate: " << interestRate * 100 << "%\n";
        std::cout << "-------------------------\n";
    }
};

int bankAccount::nextAccountNumber = 1000;  

int main() {
    const int MAX_CUSTOMERS = 10;
    bankAccount customers[MAX_CUSTOMERS] = {
        {"Alice", "Checking", 1000.0, 0.03},
        {"Bob", "Saving", 1500.0, 0.04},
        {"Charlie", "Checking", 2000.0, 0.02},
        {"David", "Saving", 2500.0, 0.05},
        {"Eva", "Checking", 1200.0, 0.03},
        {"Frank", "Saving", 1800.0, 0.04},
        {"Grace", "Checking", 1700.0, 0.02},
        {"Hannah", "Saving", 2100.0, 0.05},
        {"Isaac", "Checking", 1100.0, 0.03},
        {"Jack", "Saving", 1400.0, 0.04}
    };

    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        customers[i].displayAccountInfo();
    }

    customers[0].deposit(500);
    customers[1].withdraw(300);

    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        customers[i].applyInterest();
    }

    std::cout << "\nAfter deposits, withdrawals, and applying interest:\n";
    for (int i = 0; i < MAX_CUSTOMERS; ++i) {
        customers[i].displayAccountInfo();
    }

    return 0;
}