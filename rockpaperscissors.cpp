#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int main() {
    std::string choices[] = {"rock", "paper", "scissors"};
    int num_choices = 3;
    int user_wins = 0;
    int computer_wins = 0;

    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Play rounds until either the user or the computer has won three times
    while (user_wins < 3 && computer_wins < 3) {
        std::cout << "Enter your choice (rock, paper, or scissors): ";
        std::string user_choice;
        std::cin >> user_choice;

        // Generate a random choice for the computer
        int computer_choice_index = std::rand() % num_choices;
        std::string computer_choice = choices[computer_choice_index];

        std::cout << "Computer chose " << computer_choice << "\n";

        // Determine the winner of the round
        if (user_choice == "rock" && computer_choice == "scissors") {
            std::cout << "You win!\n";
            ++user_wins;
        }
        else if (user_choice == "paper" && computer_choice == "rock") {
            std::cout << "You win!\n";
            ++user_wins;
        }
        else if (user_choice == "scissors" && computer_choice == "paper") {
            std::cout << "You win!\n";
            ++user_wins;
        }
        else if (user_choice == computer_choice) {
            std::cout << "It's a tie!\n";
        }
        else {
            std::cout << "Computer wins!\n";
            ++computer_wins;
        }
    }

    // Print the final results
    std::cout << "\nFinal scores:\n";
    std::cout << "You: " << user_wins << "\n";
    std::cout << "Computer: " << computer_wins << "\n";

    if (user_wins > computer_wins) {
        std::cout << "You win!\n";
    }
    else {
        std::cout << "Computer wins!\n";
    }

    return 0;
}
