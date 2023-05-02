#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>

const int SIZE = 3;

void printBoard(const std::vector<std::vector<char>>& board);
bool makeHumanMove(std::vector<std::vector<char>>& board);
bool makeComputerMove(std::vector<std::vector<char>>& board);
bool checkWin(const std::vector<std::vector<char>>& board, char player);
bool isDraw(const std::vector<std::vector<char>>& board);

#endif // TICTACTOE_H
