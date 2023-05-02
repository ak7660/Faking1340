#ifndef TILE_GAME_H
#define TILE_GAME_H

#include <vector>
#include <string>

class TileGame
{
public:
    void run(int lvl);

private:
    bool tile(int lvl);
    std::vector<int> movable(const std::vector<int> &board, int row, int col, int pos);
    void print_board(const std::vector<int> &board, int row, int col);
};

#endif // tile_h
