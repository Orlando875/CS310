#include <iostream>
#include <random>
#include <iomanip>

int main() {
    // Random number generator
    std::random_device rd; 
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_real_distribution<> dis(10.0, 100.0); 

    std::cout << "25 random real numbers between 10 and 100:\n";

    for (int i = 0; i < 25; ++i) {
        double random_number = dis(gen);
        std::cout << std::fixed << std::setprecision(2) << random_number << " ";
        
        if ((i + 1) % 5 == 0) std::cout << "\n"; 
    }

    return 0;
}