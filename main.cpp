#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <fstream>
#include <cctype>
#include "mazes.h"

// Encryption and decryption functions are omitted in this example
// as they require a separate implementation using C++ cryptography libraries.

// Player ranking function
void player_ranking();

// Initiate function
int initiate();

// Story function
void story();

int main() {
    story();
    int difficulty = initiate();
    if (difficulty == 0) {
        return 0;
    }

    // Add game logic here

    return 0;
}

void player_ranking() {
    // Implement player ranking logic here
}

int initiate() {
    bool invalid = false;
    while (true) {
        std::cout << "\033[H\033[J";
        if (invalid) {
            std::cout << "->Invalid input, try again! ";
        }
        // Add logo and other prints here

        player_ranking();
        std::cout << "=====================================================================\n";
        std::cout << "\n-->Enter (Q) to exit<--\n\n";
        while (true) {
            std::string user_input;
            std::cin >> user_input;
            if (!user_input.empty() && std::isdigit(user_input[0]) && 0 < std::stoi(user_input) && std::stoi(user_input) < 4) {
                return std::stoi(user_input);
            } else if (user_input == "Q") {
                return 0;
            } else {
                invalid = true;
                break;
            }
        }
    }
}

void story() {
    system("clear");
    string x;
    cout << "Press ENTER to read the story & rules OR (E) start the game directly: ";
    getline(cin, x);
    system("clear");

    string text[] = {
        "Background story: ",
        "",
        "->In 1986, a nuclear leak accident occured nearby your hometown.",
        "->Millions of innocent villagers were exposed to highly radioactive chemicals.",
        "->You need to escape this Ghost Town as soon as possible!"
    };

    string image[] = {
        "+-----------+/__\  _      / \      /   /     ( )| | |                     |   ( )_)| | (_)_)    ",
        "|_|_|_|_|_|_||__| / \    /___\    /   /    (__)_) | | NUCLEAR POWER PLANT |  (__)_)| | | |     ",
        "|_|_|_|_|_|_|    /   \   |   |   /   /     |  | |_| |                     |   |  | |_| | |    ",
        "|_|_|_|_|_|_|   /_____\  |___|  /   /      |  |     |                     |   |  |     | |     ",
        "|_|_|_|_|_|_|   |     |        /   /       |  |     |       _______       |   |  |     | |     ",
        "|   |   |   |   |  _  |       /   /        |  |     |      |       |      |   |  |     |_|     ",
        "|___________|   |_|_|_|      /   /         |__|     |______|_______|______|   |__|                  "
    };

    if (x != "E") {
        for (const string &line : image) {
            cout << line << endl;
        }
        cout << "============================================================================================" << endl;
        for (const string &line : text) {
            for (char ch : line) {
                cout << ch;
                cout.flush();
                usleep(40000);
            }
            cout << endl;
        }
        cout << endl;
        cout << "Press ENTER to continue: ";
        getline(cin, x);
        system("clear");
        cout << "Rules: " << endl;
        cout << endl;
        cout << "->Enter (W, A, S, D) to move and find a way to the exit (E) in the maze, each move will be recorded as one step." << endl;
        cout << "->Items in the maze: (*) = Randomly played a game (difficulty of the game depends on the difficulty chose at the beginning)." << endl;
        cout << "                           If you win your steps will be decreased by 6." << endl;
        cout << "                           If you gave up or lost you will be teleported back to where you started." << endl;
        cout << "                     (?) = Random teleport." << endl;
        cout << "->Depending on the choosen difficulty level, the final score (RADIATION LEVEL) = steps X weight" << endl;
        cout << "->Difficulty 1: weight = 3, Difficulty 2: weight = 2, Difficulty 3: weight = 1." << endl;
        cout << "->The lower the RADIATION LEVEL, the higher the rank." << endl;
        cout << "->The score will only be updated on the ranking system after you reach the exit and if you are a new player OR your RADIATION LEVEL is lower than previous." << endl;
        cout << "->The goal is to escape the Ghost Town with minimum steps!" << endl;
        cout << endl;
        cout << "Press ENTER to continue: ";
        getline(cin, x);
    }
}
}
