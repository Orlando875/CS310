#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));
    
    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;
    
    cout << "Welcome to the Guessing Game!" << endl;  // Fixed typo
    cout << "I'm thinking of a number between 1 and 100." << endl;

    // Loop until the user guesses the correct number
    do {
        cout << "Enter your guess: ";
        cin >> guess;  // Fixed input operator
        attempts++;
        
        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }
    } while (guess != secretNumber);

    return 0;
}