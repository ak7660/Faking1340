#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>
#include <string>

int roll_dice() {
    return rand() % 6 + 1;
}

char get_valid_input() {
    char input;
    std::cin >> input;

    while (input != 'M' && input != 'G' && input != 'W') {
        std::cout << "Invalid input. Please enter M, G, or W: ";
        std::cin >> input;
    }

    return input;
}

int main() {
    srand(time(0));

    std::map<char, int> food_values = {{'M', 3}, {'G', 2}, {'W', 1}};
    std::string food_names[] = {"Meat", "Grass", "Water"};

    std::cout << "1. Welcome to the game 'The More You Eat; The Bigger You Get'." << std::endl;
    std::cout << "2. The game is just as simple as its name, the more you eat; the bigger you get" << std::endl;
    std::cout << "3. But these are the rules, please read this carefully" << std::endl;
    std::cout << "4. This game can be played by 2 players\n5. Each player can choose any type of food that they prefer (Meat = M, Grass = G, Water = W)" << std::endl;
    std::cout << "6. At the beginning of the game, both players must roll the dice by typing 'roll' until both players got different dice." << std::endl;
    std::cout << "7. There would be no draw in this game because both players will play until they got the winner." << std::endl;

    int player1_dice, player2_dice;
    std::string roll;
    do {
        std::cout << "Type 'roll' to roll the dice: ";
        std::cin >> roll;

        if (roll == "roll") {
            player1_dice = roll_dice();
            player2_dice = roll_dice();
            std::cout << "You rolled: " << player1_dice << ", Computer rolled: " << player2_dice << std::endl;
        }
    } while (player1_dice == player2_dice);

    int rounds = 5;
    int player1_size = 0, player2_size = 0;

    for (int i = 0; i < rounds; i++) {
        std::cout << "Round " << i + 1 << ": Choose your food (M, G, W): ";
        char player1_choice = get_valid_input();
        char player2_choice = "MGW"[rand() % 3];

        player1_size += food_values[player1_choice];
        player2_size += food_values[player2_choice];

        std::cout << "You chose " << food_names[player1_choice - 'M'] << ", Computer chose " << food_names[player2_choice - 'M'] << std::endl;
    }

    std::cout << "Final sizes - You: " << player1_size << ", Computer: " << player2_size << std::endl;

    if (player1_size > player2_size) {
        std::cout << "Congratulations! You won!" << std::endl;
    } else {
        std::cout << "Sorry, the computer won. Better luck next time!" << std::endl;
    }

    return 0;
}
