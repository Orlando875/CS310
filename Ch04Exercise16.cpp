#include <iostream>
#include <iomanip>
using namespace std;

const double FIXED_ADVANCE = 5000.0;                
const double PUBLICATION_PAYMENT = 20000.0;         
const double ROYALTY_RATE_OPTION_2 = 0.125;         
const double ROYALTY_RATE_OPTION_3_FIRST_4000 = 0.10;  
const double ROYALTY_RATE_OPTION_3_AFTER_4000 = 0.14;   

double calculateOption1();
double calculateOption2(double netPrice, int estimatedSales);
double calculateOption3(double netPrice, int estimatedSales);
string findBestOption(double option1, double option2, double option3);

int main() {
    double netPrice;
    int estimatedSales;

    cout << "Enter the net price of each copy of the novel: $";
    cin >> netPrice;
    cout << "Enter the estimated number of copies to be sold: ";
    cin >> estimatedSales;

    double royaltyOption1 = calculateOption1();
    double royaltyOption2 = calculateOption2(netPrice, estimatedSales);
    double royaltyOption3 = calculateOption3(netPrice, estimatedSales);

    cout << fixed << setprecision(2);
    cout << "\nRoyalties under Option 1: $" << royaltyOption1 << endl;
    cout << "Royalties under Option 2: $" << royaltyOption2 << endl;
    cout << "Royalties under Option 3: $" << royaltyOption3 << endl;

    string bestOption = findBestOption(royaltyOption1, royaltyOption2, royaltyOption3);
    cout << "\nThe best option is: " << bestOption << endl;

    return 0;
}

double calculateOption1() {
    return FIXED_ADVANCE + PUBLICATION_PAYMENT;
}

double calculateOption2(double netPrice, int estimatedSales) {
    return ROYALTY_RATE_OPTION_2 * netPrice * estimatedSales;
}

double calculateOption3(double netPrice, int estimatedSales) {
    if (estimatedSales <= 4000) {
        return ROYALTY_RATE_OPTION_3_FIRST_4000 * netPrice * estimatedSales;
    } else {
        double first4000Royalty = ROYALTY_RATE_OPTION_3_FIRST_4000 * netPrice * 4000;
        double remainingRoyalty = ROYALTY_RATE_OPTION_3_AFTER_4000 * netPrice * (estimatedSales - 4000);
        return first4000Royalty + remainingRoyalty;
    }
}

string findBestOption(double option1, double option2, double option3) {
    if (option1 >= option2 && option1 >= option3) {
        return "Option 1";
    } else if (option2 >= option1 && option2 >= option3) {
        return "Option 2";
    } else {
        return "Option 3";
    }
}
