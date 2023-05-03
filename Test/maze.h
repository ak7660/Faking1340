#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <string>

class Maze {
public:
    Maze(std::istream& input);
    void print() const;
    int move_player(char command, bool won_mini_game = false);
    bool check_win() const;
    void teleport_to_start();

private:
    std::vector<std::string> map;
    int player_x, player_y;
};

#endif // MAZE_H
