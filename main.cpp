#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <fstream>
#include <cctype>
#include "mazes.h"
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <random>
using namespace std;

// Encryption and decryption functions are omitted in this example
// as they require a separate implementation using C++ cryptography libraries.

// Player ranking function
void player_ranking();

// Initiate function
int initiate();

// Story function
void story();

// Global variable to store the generated maze
std::vector<std::vector<char>> maze;

void printLogo() {
    std::vector<std::string> logo = {
        "  ________ __                    __    ___________                   ",
        " /  _____/|  |__   ____  _______/  |_  \\__    ___/_____  _  ______   ",
        "/   \\  ___|  |  \\ /  _ \\/  ___/\\   __\\   |    | /  _ \\ \\/ \\/ /    \\  ",
        "\\    \\_\\  \\   Y  (  <_> )___ \\ |  |      |    |(  <_> )     /   |  \\ ",
        "\\______  /___|  /\\____/____  > |__|      |____| \\____/ \\/\\_/|___|  / ",
        "       \\/     \\/           \\/                                    \\/  "
    };

    for (const auto& line : logo) {
      std::cout << line << std::endl;
    }
}


void player_ranking() {
    // Implement player ranking logic here
}

int initiate() {
    bool invalid = false;
    while (true) {
        system("clear"); // On Linux and macOS, use "clear" instead of "cls"
        if (invalid) {
            std::cout << "->Invalid input, try again!" << std::endl;
        }
        std::cout << "=====================================================================" << std::endl;
        printLogo();
        playerRanking();
        std::cout << "=====================================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "-->Enter (Q) to exit<--" << std::endl;
        std::cout << std::endl;

        std::string user_input;
        std::getline(std::cin, user_input);

        if (user_input.length() == 1) {
            if (isdigit(user_input[0]) && std::stoi(user_input) > 0 && std::stoi(user_input) < 4) {
                return std::stoi(user_input);
            } else if (user_input == "Q" || user_input == "q") {
                return -1;
            } else {
                invalid = true;
            }
        } else {
            invalid = true;
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

// Randomly distributed the items on the maze
void generate(int difficulty) {
    const std::vector<std::string>* maze_temp;

    if (difficulty == 1) {
        maze_temp = &maze1;
    } else if (difficulty == 2) {
        maze_temp = &maze2;
    } else if (difficulty == 3) {
        maze_temp = &maze3;
    } else {
        std::cerr << "Invalid difficulty value" << std::endl;
        return;
    }

    maze.clear();
    for (const std::string& line : *maze_temp) {
        std::vector<char> temp(line.begin(), line.end());
        maze.push_back(temp);
    }

void distribute_items(int difficulty) {
    int num_stars, num_tp;
    
    if (difficulty == 1) {
        num_stars = 8;
        num_tp = 5;
    } else if (difficulty == 2) {
        num_stars = 15;
        num_tp = 10;
    } else if (difficulty == 3) {
        num_stars = 25;
        num_tp = 20;
    }

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> row_dist(0, maze.size() - 1);
    std::uniform_int_distribution<int> col_dist(0, maze[0].size() - 1);

    int num = 0;
    while (num != num_stars) {
        int row = row_dist(mt);
        int column = col_dist(mt);
        if (maze[row][column] == ' ') {
            maze[row][column] = '*';
            num++;
        }
    }

    num = 0;
    while (num != num_tp) {
        int row = row_dist(mt);
        int column = col_dist(mt);
        if (maze[row][column] == ' ') {
            maze[row][column] = '?';
            num++;
        }
    }
}

void show() {
    std::string display = "";
    for (const auto& row : maze) {
        for (const auto& cell : row) {
            display += cell;
        }
        display += " \n";
    }
    std::cout << display;
}
    
std::pair<int, int> get_position() {
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[i].size(); ++j) {
            if (maze[i][j] == 'O') {
                return {i, j};
            }
        }
    }
    return {-1, -1}; // Return an invalid position if not found
}

std::vector<char> possible_moves(int row, int column) {
    std::vector<char> moves;
    std::vector<char> possibles = {' ', '?', '*', 'E'};
    
    if (std::find(possibles.begin(), possibles.end(), maze[row - 1][column]) != possibles.end()) {
        moves.push_back('W');
    }
    if (std::find(possibles.begin(), possibles.end(), maze[row + 1][column]) != possibles.end()) {
        moves.push_back('S');
    }
    if (std::find(possibles.begin(), possibles.end(), maze[row][column - 1]) != possibles.end()) {
        moves.push_back('A');
    }
    if (std::find(possibles.begin(), possibles.end(), maze[row][column + 1]) != possibles.end()) {
        moves.push_back('D');
    }

    return moves;
}

int move_O(char direction, int row, int column, bool& quit) {
    std::system("CLS"); // Clear console on Windows; use "clear" for Unix-based systems

    char item = ' ';
    if (direction == 'Q') {
        quit = true;
        return -1;
    }
    maze[row][column] = ' ';

    if (direction == 'W') {
        item = maze[row - 1][column];
        maze[row - 1][column] = 'O';
    } else if (direction == 'S') {
        item = maze[row + 1][column];
        maze[row + 1][column] = 'O';
    } else if (direction == 'A') {
        item = maze[row][column - 1];
        maze[row][column - 1] = 'O';
    } else if (direction == 'D') {
        item = maze[row][column + 1];
        maze[row][column + 1] = 'O';
    }

    if (item == ' ') {
        return -1; // None
    } else if (item == 'E') {
        return 0; // Win
    } else if (item == '*') {
        return 1; // Game
    } else if (item == '?') {
        return 2; // Transport
    }

    return -1;
}

int main() {
    bool breaker = false;
    bool breaker2 = false;
    srand(time(NULL));

    while (true) {
        while (true) {
            int difficulty = initiate();
            std::string player_name;
            if (difficulty != -1) {
                player_name = name();
            }
            if (difficulty == -1 || player_name.empty()) {
                std::cout << "->BYE BYE~" << std::endl;
                breaker = true;
                break;
            }
            generate(difficulty);
            distribute_items(difficulty);
            int quit = false;
            int step = 0;
            int weight = 0;
            if (difficulty == 1) {
                weight = 3;
            } else if (difficulty == 2) {
                weight = 2;
            } else if (difficulty == 3) {
                weight = 1;
            }
            show();

            while (true) {
                quit = false;
                int event = -1;
                std::pair<int, int> pos = get_position();
                int row = pos.first, column = pos.second;
                std::vector<char> moves_vec = possible_moves();
                std::string moves(moves_vec.begin(), moves_vec.end());
                char move;
                std::cout << "Enter a move (" << moves << ") OR (Q) back to Menu: ";
                std::cin >> move;

                if (std::cin && (moves.find(move) != std::string::npos || move == 'Q')) {
                    event = move_O(move);
                    step++;
                } else {
                    std::cout << "->Invalid input" << std::endl;
                }
                if (quit) {
                    step--;
                    char sure;
                    std::cout << "->Press (Q) again to quit OR else return.(Your result will not be saved before you reach the exit!): ";
                    std::cin >> sure;
                    if (sure == 'Q') {
                        std::cout << std::endl << player_name << " left the game!" << std::endl;
                        breaker2 = true;
                        break;
                    }
                }
                if (event == -1) {
                    continue;
                } else if (event == 0) {
                    show();
                    std::cout << "Congratulations " << player_name << "! It took you " << step << " steps to reach the Exit!" << std::endl;
                    std::cout << std::endl << "Your corresponding RADIATION LEVEL = " << step << " X " << weight << " = " << step*weight << std::endl;
                    std::cout << std::endl << "This will be automatically updated on the ranking system if you are a new player OR your RADIATION LEVEL is lower than previous." << std::endl;
                    insert_player(player_name, step, difficulty);
                    std::cout << std::endl;
                    std::cin.ignore();
                    std::cout << "Press ENTER to continue: ";
                    std::cin.get();
                    break;
                } else if (event == 1) {
                    game();
                } else if (event == 2) {
                    std::pair<int, int> pos = get_position();
                    row = pos.first, column = pos.second;
                    teleport(row, column);
                }
                show();
                show_player_information();
            }
            if (breaker2) {
                break;
            }
            if (breaker) {
                break;
            }
        }
        if (breaker) {
            break;
        }
    }

    return 0;
}
