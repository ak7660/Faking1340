#include <iostream>
#include <ctime>
#include <cstdlib>
#include "maze.h"

Maze::Maze(std::istream& input) {
    std::srand(std::time(0));

    std::string line;
    while (std::getline(input, line)) {
        map.push_back(line);
    }

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == 'O') {
                player_x = j;
                player_y = i;
            }
        }
    }
}

void Maze::print() const {
    for (const auto& line : map) {
        std::cout << line << std::endl;
    }
}

int Maze::move_player(char command, bool won_mini_game) {
    int new_x = player_x;
    int new_y = player_y;

    switch (command) {
        case 'w': // move up
            new_y--;
            break;
        case 'a': // move left
            new_x--;
            break;
        case 's': // move down
            new_y++;
            break;
        case 'd': // move right
            new_x++;
            break;
        default:
            return 0; // Invalid move
    }

    if (map[new_y][new_x] == 'E') {
        return 4; // Player has reached the exit ('E')
    } else if (map[new_y][new_x] == ' ') {
        map[player_y][player_x] = ' ';
        player_x = new_x;
        player_y = new_y;
        map[player_y][player_x] = 'O';
        return 1; // Successful move
    } else if (map[new_y][new_x] == '*') {
        map[player_y][player_x] = ' ';
        player_x = new_x;
        player_y = new_y;
        map[player_y][player_x] = 'O';
        return 2; // Stepped on a mine
    } else if (map[new_y][new_x] == '?') {
        map[player_y][player_x] = ' ';
        int random_x, random_y;
        do {
            random_y = std::rand() % map.size();
            random_x = std::rand() % map[random_y].size();
        } while (map[random_y][random_x] != ' ' || map[random_y][random_x] == '#');

        player_x = random_x;
        player_y = random_y;
        map[player_y][player_x] = 'O';
        map[new_y][new_x] = ' ';
        return 3; // Teleported
    }

    return 0; // Invalid move
}

void Maze::teleport_to_start() {
    // Clear the current player position
    map[player_y][player_x] = ' ';

    // Set the player's position to the top-left corner
    player_x = 1;
    player_y = 1;

    // Update the player's position
    map[player_y][player_x] = 'O';
}

bool Maze::check_win() const {
    return (player_y == 0 && player_x == map[0].size() - 2);
}
