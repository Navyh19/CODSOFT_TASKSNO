#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;
    int userGuess = 0;
    
    std::cout << "=================================\n";
    std::cout << "      NUMBER GUESSING GAME       \n";
    std::cout << "=================================\n";
    std::cout << "I have chosen a number between 1 and 100. Try to guess it!\n\n";

    // Loop until the user guesses correctly
    while (userGuess != secretNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess > secretNumber) {
            std::cout << "Too high! Try again.\n\n";
        } else if (userGuess < secretNumber) {
            std::cout << "Too low! Try again.\n\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << secretNumber << "\n";
        }
    }

    return 0;
}

Task 1: Number Guessing Game
