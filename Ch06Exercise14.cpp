#include <iostream>
using namespace std;

double calculateBillingAmount(double hourlyRate, int consultingTime, bool isLowIncome) {
    double billingAmount = 0.0;

    if (isLowIncome) {
        if (consultingTime > 30) {
            billingAmount = hourlyRate * 0.40 * ((consultingTime - 30) / 60.0);
        }
    } else {
        if (consultingTime > 20) {
            billingAmount = hourlyRate * 0.70 * ((consultingTime - 20) / 60.0);
        }
    }

    return billingAmount;
}

int main() {
    double hourlyRate;
    int consultingTime;
    char lowIncomeChar;
    bool isLowIncome;

    cout << "Enter the hourly rate: ";
    cin >> hourlyRate;

    cout << "Enter the consulting time in minutes: ";
    cin >> consultingTime;

    cout << "Does the person have low income? (Y/N): ";
    cin >> lowIncomeChar;

    isLowIncome = (lowIncomeChar == 'Y' || lowIncomeChar == 'y');

    double billingAmount = calculateBillingAmount(hourlyRate, consultingTime, isLowIncome);

    cout << "The billing amount is: $" << fixed << setprecision(2) << billingAmount << endl;

    return 0;
}