#include "number_guessing_game.h"

int main() {
    playNumberGuessingGame();
    return 0;
}



#include "number_guessing_game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

void playNumberGuessingGame() {
    // Initialize random seed
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have picked a number between 1 and 100." << std::endl;
    std::cout << "Can you guess the number?" << std::endl;

    // Main game loop
    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess > randomNumber) {
            std::cout << "Your guess is too high!" << std::endl;
        } else if (userGuess < randomNumber) {
            std::cout << "Your guess is too low!" << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number!" << std::endl;
            std::cout << "It took you " << attempts << " attempts." << std::endl;
        }
    } while (userGuess != randomNumber);
}
