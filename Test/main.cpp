#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include "maze.h"
#include "minigame.h"

// Clear the screen
void clear_screen() {
#ifdef _WIN32
    std::system("CLS");
#else
    std::system("clear");
#endif
}

// Print the menu
void print_menu(int high_score) {
    std::cout << R"(                                                                                                         
    -`^'-         \-^-/          )))           ___           (((          -`^'-          |||      
    (o o)         (o o)         (o o)         (o o)         (o o)         (o o)         (o o)     
ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-
   
                        ___ _   ____  ___  ___   _   _    ___ _____ 
                        |_  | | | |  \/  | / _ \ | \ | |  |_  |_   _|
                            | | | | | .  . |/ /_\ \|  \| |    | | | |  
                            | | | | | |\/| ||  _  || . ` |    | | | |  
                        /\__/ / |_| | |  | || | | || |\  |/\__/ /_| |_ 
                        \____/ \___/\_|  |_/\_| |_/\_| \_/\____/ \___/ 
                                               
                                                                                                                                                
    -`^'-         \-^-/          )))           ___           (((          -`^'-          |||      
    (o o)         (o o)         (o o)         (o o)         (o o)         (o o)         (o o)     
ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-
    )" << std::endl;

    std::cout << "\nWelcome to the Jumanji Adventure Game!\n\n";
    std::cout << "1. Start a new game 🚀\n";
    std::cout << "2. Quit the game 🏳️\n";
    std::cout << "🏆 Highest Score (Least steps taken): " << high_score << " steps\n\n";
    std::cout << "Choose an option by entering the corresponding number: ";
}

// Read the highest score form the high_score.txt file gnerated
int read_high_score(const std::string& filename) {
    std::ifstream file(filename);
    int high_score = std::numeric_limits<int>::max();

    if (file.is_open()) {
        file >> high_score;
        file.close();
    }

    return high_score;
}

// Write the high score into the file high_score.txt
void write_high_score(const std::string& filename, int high_score) {
    std::ofstream file(filename);

    if (file.is_open()) {
        file << high_score;
        file.close();
    }
}

// Main program
int main() {
    // Load the randomly generated map in maze.txt
    std::string maze_file = "maze.txt";
    std::string high_score_file = "high_score.txt";
    std::ifstream input(maze_file);
    int high_score = read_high_score(high_score_file);

    // Check if it can be opened
    if (!input.is_open()) {
        std::cerr << "Error: couldn't open the maze file." << std::endl;
        return 1;
    }

    // Show the menu and the Rock
    while (true) {
        clear_screen();
        Maze maze(input);
        input.clear();
        input.seekg(0, std::ios::beg);

        MiniGame minigame;
        bool valid_option = false;

        while (!valid_option) {
            print_menu(high_score);
            std::cout << "Choose an option: ";
            char option;
            std::cin >> option;

            if (option == '1') {
                valid_option = true;
            } else if (option == '2') {
                std::cout << "Quitting the game..." << std::endl;
                input.close();
                return 0;
            } else {
                std::cout << "Invalid input" << std::endl;
                clear_screen();
                continue;
            }
        }

        // Text animation showing rules and story
        clear_screen();
        const std::string face = R"(
⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠈⠈⠉⠉⠈⠈⠈⠉⠉⠉⠉⠉⠉⠉⠉⠙⠻⣄⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠓⣄⠀⠀⢀⠀⢀⣀⣤⠄⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⣉⣩⣤⠴⠶⠶⠒⠛⠛⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣴⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣧⠤⠶⠒⠚⠋⠉⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⣾⡍⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣫⣭⣷⠶⢶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠶⠶⠖⠚⠛⠛⣹⠏⠀⠀⠀⠀⠀⠀⠀⠀⠴⠛⠛⠉⡁⠀⠀⠙⠻⣿⣷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢠⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⡷⠷⢿⣦⣤⣈⡙⢿⣿⢆⣴⣤⡄⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣠⣤⡀⣸⡄⠀⠀⠀⠀⠀⠀⠀⢀⣤⣿⣿⣟⣩⣤⣴⣤⣌⣿⣿⣿⣦⣹⣿⢁⣿⣿⣄⣀⡀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢠⣿⠋⠻⢿⡁⠀⠀⠀⠀⠀⠀⠀⠀⢸⡿⠿⠛⢦⣽⣿⣿⢻⣿⣿⣿⣿⠋⠁⠘⣿⣿⣿⣿⣿⣿⣼⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢸⣿⠁⠀⠀⠙⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠿⣿⣯⣼⣿⡿⠟⠃⠀⠀⠀⣿⣿⣿⣿⣿⡛⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢸⣧⣴⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣺⠟⠃⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⢁⣀⣀⣀⣀⣀⣠⣀⣀⢀⢀⢀
⠀⠀⢿⠿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⡆⠙⠛⠛⠙⢻⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⡇⠀⠘⠃⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡟⢿⣿⣆⠀⣸⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢄⡼⠁⢀⣀⡀⠀⠀⠀⣦⣄⠀⣠⡄⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣷⣬⢻⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣧⣰⣿⡿⠿⠦⢤⣴⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣸⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠛⠛⠒⣿⣿⣿⡿⠟⠹⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⠸⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⡖⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡿⣾⣿⣸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣆⣀⣀⣤⣴⣶⣶⣾⣿⣷⣦⣴⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡇⣿⣿⡛⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⢾⡟⠛⠛⠻⠛⠛⠛⠿⠿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠓⢁⣬⣿⠇⠀⠀⠀⠀⠀⢠⡀⠀⠀⠀⠀⠀⢰⡿⣻⠇⠀⠀⠀⠀⠀⣠⣶⣶⣶⣶⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⢐⣯⠞⠁⠀⠀⠀⠀⠀⠀⣄⠱⣄⠀⠀⠀⠀⠸⡧⠟⠆⠀⠀⠀⠀⠘⠿⢿⠿⠿⣿⡿⣿⠃⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠘⢦⡈⠂⠀⠑⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢠⣿⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠒⡄⠀⠀⠑⠄⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣦⣦⣼⡏⠳⣜⢿⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⢠⣷⣦⣤⣀⣀⣀⣴⣿⣿⣿⣿⣿⡿⠻⠆⠸⣎⣧⠀⠈⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⣠⡄⠀⣿⢹⡇⢸⡀⠀⠈⠻⢿⣿⣿⣿⣿⣿⣿
)";

        std::cout << face << std::endl;
        std::cout << "My friend, listen carefully to the Rules: " << std::endl;
        std::cout << std::endl;
        std::cout << "->Enter (W, A, S, D) to move and find a way to the exit (E) in the maze, each move will be recorded as one step." << std::endl;
        std::cout << "->Items in the maze: (*) = Randomly played a game." << std::endl;
        std::cout << "                     If you lost you will be teleported back to where you started." << std::endl;
        std::cout << "                     (?) = Random teleport." << std::endl;
        std::cout << "->The goal is to escape this place with minimum steps! " << std::endl;
        std::cout << "Welcome to the Maze Game!\nPress Enter to start...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        clear_screen();

        int steps_taken = 0;
        char command;

        // Maze game loop
        while (true) {
            // Print the maze each time after a move
            clear_screen();
            maze.print();
            std::cout << "Steps taken -----------> " << steps_taken << std::endl;
            std::cout << "Enter command (w/a/s/d, q to quit): ";
            std::cin >> command;

            if (command == 'q') {
                std::cout << "Returning to the main menu..." << std::endl;
                // After quitting the game, 
                // Close the input stream
                input.close();

                // Remove the existing maze.txt and generate a new one
                system("rm -rf maze.txt pospos.txt");
                system("make generate");

                // Re-open the input stream with the new maze.txt
                input.open(maze_file);
                if (!input.is_open()) {
                    std::cerr << "Error: couldn't open the maze file." << std::endl;
                    return 1;
                     }
                break;
            }
            // Cases for player movement
            int move_result = maze.move_player(command);
            bool won_minigame = false;

            switch (move_result) {
                case 1: // Successful move
                    steps_taken++;
                    break;
                case 2: // Stepped on a mine
                    steps_taken++;
                    clear_screen();
                    won_minigame = minigame.play_random_game();
                    clear_screen();
                    if (!won_minigame) {
                        maze.teleport_to_start();
                    }
                    break;
                case 3: // Teleported
                    steps_taken++;
                    break;
                case 4: // Reached the exit ('E')
                    steps_taken++;
                    std::cout << "Congratulations! You have completed the maze." << std::endl;
                    std::cout << "Your final score: " << steps_taken << " steps" << std::endl;
                    if (high_score == 0) {
                        high_score = steps_taken;
                        write_high_score(high_score_file, high_score);
                        std::cout << "New High Score!" << std::endl;
                    }
                    if (steps_taken < high_score) {
                        high_score = steps_taken;
                        write_high_score(high_score_file, high_score);
                        std::cout << "New High Score!" << std::endl;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    
                    // Close the input stream
                    input.close();

                    // Remove the existing maze.txt and generate a new one
                    system("rm -rf maze.txt pospos.txt");
                    system("make generate");

                    // Re-open the input stream with the new maze.txt
                    input.open(maze_file);
                    if (!input.is_open()) {
                        std::cerr << "Error: couldn't open the maze file." << std::endl;
                        return 1;
                        }
                    break;
                default: // Invalid move
                    std::cout << "Invalid command!" << std::endl;
                    break;
            }

            if (move_result == 4) {
                break;
            }
        }
    } // This is the missing closing curly brace for the outer while loop.

    input.close();
    return 0;
}
