#include <iostream>
#include <iomanip> // For controlling output format

int main() {
    double originalPrice, markupPercentage, salesTaxRate;
    
    std::cout << "Enter the original price of the item: $";
    std::cin >> originalPrice;
    
    std::cout << "Enter the percentage of the mark-up: ";
    std::cin >> markupPercentage;
    
    std::cout << "Enter the sales tax rate (as a percentage): ";
    std::cin >> salesTaxRate;
    
    double sellingPrice = originalPrice * (1 + markupPercentage / 100);
    
    double salesTax = sellingPrice * (salesTaxRate / 100);
    
    double finalPrice = sellingPrice + salesTax;
    
    std::cout << std::fixed << std::setprecision(2); // Set precision to 2 decimal places
    
    std::cout << "\nOriginal price: $" << originalPrice << std::endl;
    std::cout << "Markup percentage: " << markupPercentage << "%" << std::endl;
    std::cout << "Store's selling price: $" << sellingPrice << std::endl;
    std::cout << "Sales tax rate: " << salesTaxRate << "%" << std::endl;
    std::cout << "Sales tax: $" << salesTax << std::endl;
    std::cout << "Final price of the item: $" << finalPrice << std::endl;

    return 0;
}