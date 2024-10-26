#include <iostream>
#include <iomanip>
using namespace std;

class bankAccount {
protected:
    int accountNumber;
    double balance;

public:
    bankAccount(int accNum = 0, double bal = 0.0) : accountNumber(accNum), balance(bal) {}

    void setAccountNumber(int accNum) { accountNumber = accNum; }
    int getAccountNumber() const { return accountNumber; }

    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
    }

    virtual void printAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

class checkingAccount : public bankAccount {
private:
    double interestRate;
    double minBalance;
    double serviceCharge;

public:
    checkingAccount(int accNum = 0, double bal = 0.0, double intRate = 0.0, double minBal = 0.0, double servCharge = 0.0)
        : bankAccount(accNum, bal), interestRate(intRate), minBalance(minBal), serviceCharge(servCharge) {}

    void setInterestRate(double intRate) { interestRate = intRate; }
    double getInterestRate() const { return interestRate; }

    void setMinBalance(double minBal) { minBalance = minBal; }
    double getMinBalance() const { return minBalance; }

    void setServiceCharge(double servCharge) { serviceCharge = servCharge; }
    double getServiceCharge() const { return serviceCharge; }

    void postInterest() {
        balance += balance * (interestRate / 100);
    }

    bool isBelowMinBalance() const {
        return balance < minBalance;
    }

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            if (isBelowMinBalance()) {
                cout << "Balance is below minimum; applying service charge of $" << serviceCharge << endl;
                balance -= serviceCharge;
            }
            balance -= amount;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    // Account Information that is printed
    void printAccountInfo() const override {
        bankAccount::printAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Minimum Balance: $" << fixed << setprecision(2) << minBalance << endl;
        cout << "Service Charge: $" << fixed << setprecision(2) << serviceCharge << endl;
    }
};

class savingsAccount : public bankAccount {
private:
    double interestRate;

public:
    savingsAccount(int accNum = 0, double bal = 0.0, double intRate = 0.0)
        : bankAccount(accNum, bal), interestRate(intRate) {}

    void setInterestRate(double intRate) { interestRate = intRate; }
    double getInterestRate() const { return interestRate; }

    void postInterest() {
        balance += balance * (interestRate / 100);
    }

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient funds." << endl;
    }

    void printAccountInfo() const override {
        bankAccount::printAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Code to test all the classes
int main() {
    // Test checking account
    cout << "Checking Account:\n";
    checkingAccount checkAcc(12345, 500.0, 1.5, 100.0, 15.0);
    checkAcc.printAccountInfo();
    checkAcc.deposit(200.0);
    checkAcc.withdraw(50.0);
    checkAcc.postInterest();
    checkAcc.printAccountInfo();

    cout << "\nSavings Account:\n";
    // Test savings account
    savingsAccount saveAcc(54321, 1000.0, 2.0);
    saveAcc.printAccountInfo();
    saveAcc.deposit(300.0);
    saveAcc.withdraw(100.0);
    saveAcc.postInterest();
    saveAcc.printAccountInfo();

    return 0;
}