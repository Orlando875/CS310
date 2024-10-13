#include <iostream>  // needed for cout, cin
#include <iomanip>   // needed for output formatting

// Function declarations
int capturePositiveNumberInput();
bool identifyIfWinner(int userNumber, int scratchTicketNumbers[5][5]);

int main() {
    // creating local variables for the program
    bool loopActive = true;
    bool winningTicket;
    char keepPlaying;
    const int NUMBER_OF_ROWS = 5;
    const int NUMBER_OF_COLUMNS = 5;
    int providedWinningNumber;
    
    // providing values for arrays
    int winningArray[NUMBER_OF_ROWS] = { 15, 65, 84, 2, 33 };
    int scratchTicketNumbers[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = {
        {34, 94, 34, 56, 8},
        {6, 48, 7, 32, 8},
        {4, 89, 32, 72, 14},
        {8, 64, 34, 28, 64},
        {6, 18, 5, 87, 22}
    };

    // Displaying intro to the application
    std::cout << "\n\n  Let's play the lottery!"
        << "\n\n  For $20 you get one 5x5 scratcher"
        << "\n  You'll get to submit a number between 1 and 500."
        << "\n  If the sum of any row is equal to your number, you win $1,000!";
    std::cout << std::endl;

    // Program loop
    do {
        // capturing user input
        providedWinningNumber = capturePositiveNumberInput();

        // outputting scratch ticket numbers
        std::cout << "\n\n  Your scratch ticket numbers are: ";
        for (int row = 0; row < NUMBER_OF_ROWS; row++) {
            std::cout << "\n ";
            for (int column = 0; column < NUMBER_OF_COLUMNS; column++) {
                std::cout << " " << scratchTicketNumbers[row][column] << " ";
            }
        }

        // identifying if the user won
        winningTicket = identifyIfWinner(providedWinningNumber, scratchTicketNumbers);

        // informing user of win or loss then prompting for another attempt
        if (winningTicket) {
            std::cout << "\n\n  You won $1,000!!";
        } else {
            std::cout << "\n\n  Sorry, you did not win...";
        }

        std::cout << "\n\n  Want to buy another?"
            << "\n  Enter Y to buy another. Otherwise, provide any other character and press enter to exit: ";
        std::cin >> keepPlaying;

        if (!(keepPlaying == 'Y' || keepPlaying == 'y')) {
            loopActive = false;
        }

    } while (loopActive);
    
    // Display closing messages
    std::cout << "\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;
    
    std::cin.get();  // waits for the user to press any key to exit

    return 0;
}

// Function to identify winner
bool identifyIfWinner(int userNumber, int scratchTicketNumbers[5][5]) {
    bool winner = false;

    // sum each row and check if any row matches the user number
    for (int row = 0; row < 5; row++) {
        int sum = 0;
        for (int column = 0; column < 5; column++) {
            sum += scratchTicketNumbers[row][column];  // access the array using []
        }

        if (sum == userNumber) {
            winner = true;  // user wins if any row sum matches
        }
    }

    return winner;
}

// Function to ensure user input is a positive number between 1 and 500
int capturePositiveNumberInput() {
    int updatedInput = 0;
    bool validInput = false;

    // modified version of input validation loop
    char errorMessage[] = "error";  // error message string
    do {
        try {
            std::cout << "\n  Please provide a whole number between 1 and 500: ";
            std::cin >> updatedInput;

            if (!std::cin || updatedInput < 1 || updatedInput > 500) {
                throw errorMessage;
            }
            validInput = true;

        } catch (const char messageStr[]) {
            std::cout << "\n  The provided input was not valid. Please try again.";
            std::cin.clear();  // clear the error state of std::cin
            std::cin.ignore(100, '\n');  // ignore any leftover characters
        }

    } while (!validInput);

    return updatedInput;
}