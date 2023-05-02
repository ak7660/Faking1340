#include <iostream>
#include <vector>
#include <cstdlib>
#include "tictactoe.h"

#define SIZE 3

void printBoard(const std::vector<std::vector<char> >& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j] << (j < SIZE - 1 ? '|' : '\n');
        }
        if (i < SIZE - 1) {
            std::cout << "-----\n";
        }
    }
}

bool makeHumanMove(std::vector<std::vector<char> >& board) {
    int row, col;
    while (true) {
        std::cout << "Enter your move (row and column, 1-3): ";
        std::cin >> row >> col;
        if (row >= 1 && row <= SIZE && col >= 1 && col <= SIZE && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = 'X';
            break;
        } else {
            std::cout << "Invalid move. Please try again.\n";
        }
    }
    return checkWin(board, 'X') || isDraw(board);
}

bool makeComputerMove(std::vector<std::vector<char> >& board) {
    int row, col;
    while (true) {
        row = std::rand() % SIZE;
        col = std::rand() % SIZE;
        if (board[row][col] == ' ') {
            board[row][col] = 'O';
            break;
        }
    }
    return checkWin(board, 'O') || isDraw(board);
}

bool checkWin(const std::vector<std::vector<char> >& board, char player) {
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

bool isDraw(const std::vector<std::vector<char> >& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
