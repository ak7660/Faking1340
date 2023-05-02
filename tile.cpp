#include "tile.h"
#include <iostream>
#include <algorithm>
#include <random>

void TileGame::run(int lvl)
{
    if (tile(lvl))
    {
        std::cout << "Congratulations! You have solved the puzzle!" << std::endl;
    }
    else
    {
        std::cout << "You gave up. Better luck next time!" << std::endl;
    }
}

bool TileGame::tile(int lvl)
{
    int row, col;
    if (lvl == -1)
    {
        // Custom level - ask user for row and col sizes
    }
    else if (lvl == 1)
    {
        row = 3;
        col = 3;
    }
    else if (lvl == 2)
    {
        row = 4;
        col = 4;
    }
    else if (lvl == 3)
    {
        row = 5;
        col = 5;
    }
    else
    {
        return false;
    }

    // Initialize the board
    std::vector<int> board(row * col);
    for (int i = 0; i < row * col - 1; ++i)
    {
        board[i] = i + 1;
    }
    board[row * col - 1] = 0;

    // Shuffle the board
    std::random_device rd;
    std::mt19937 g(rd());
    do
    {
        std::shuffle(board.begin(), board.end(), g);
    } while (std::is_sorted(board.begin(), board.end() - 1));

    // Main game loop
    while (!std::is_sorted(board.begin(), board.end() - 1))
    {
        print_board(board, row, col);
        int pos = std::find(board.begin(), board.end(), 0) - board.begin();
        std::vector<int> valid_moves = movable(board, row, col, pos);
        int move;
        std::cout << "Enter a valid number to move or -1 to give up: ";
        std::cin >> move;
        while (std::find(valid_moves.begin(), valid_moves.end(), move) == valid_moves.end() && move != -1)
        {
            std::cout << "Invalid input. Please enter a valid number to move or -1 to give up: ";
            std::cin >> move;
        }
        if (move == -1)
        {
            return false;
        }
        std::swap(board[pos], board[std::find(board.begin(), board.end(), move) - board.begin()]);
    }
    return true;
}

std::vector<int> TileGame::movable(const std::vector<int> &board, int row, int col, int pos)
{
    std::vector<int> moves;
    if (pos % col > 0)
    {
        moves.push_back(board[pos - 1]);
    }
    if (pos % col < col - 1)
    {
        moves.push_back(board[pos + 1]);
    }
    if (pos / col > 0)
    {
        moves.push_back(board[pos - col]);
    }
    if (pos / col < row - 1)
    {
        moves.push_back(board[pos + col]);
    }
    return moves;
}

void TileGame::print_board(const std::vector<int> &board, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (board[i * col + j] == 0)
            {
                std::cout << "   ";
            }
            else
            {
                std::cout.width(3);
                std::cout << board[i * col + j];
            }
        }
        std::cout << std::endl;
    }
}
