#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

class negativeNumber : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Length cannot be negative.";
    }
};

class nonNumber : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Input must be a number.";
    }
};

double convertToCentimeters(double feet, double inches) {
    const double CENTIMETERS_PER_INCH = 2.54;
    const double INCHES_PER_FOOT = 12.0;
    return ((feet * INCHES_PER_FOOT) + inches) * CENTIMETERS_PER_INCH;
}

double getValidatedInput(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        
        try {
            for (char c : input) {
                if (!isdigit(c) && c != '.' && c != '-') {
                    throw nonNumber();
                }
            }
            double value = std::stod(input);
            if (value < 0) {
                throw negativeNumber();
            }
            return value;
        } 
        catch (nonNumber& e) {
            std::cout << e.what() << " Please enter a valid number.\n";
        } 
        catch (negativeNumber& e) {
            std::cout << e.what() << " Please enter a positive number.\n";
        } 
        catch (...) {
            std::cout << "An unknown error occurred. Please try again.\n";
        }
    }
}

int main() {
    std::cout << "This program converts feet and inches to centimeters.\n";

    double feet = getValidatedInput("Enter feet: ");
    double inches = getValidatedInput("Enter inches: ");

    double centimeters = convertToCentimeters(feet, inches);

    std::cout << "Equivalent length in centimeters: " << centimeters << " cm\n";

    return 0;
}