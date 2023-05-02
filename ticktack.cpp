#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "tictactoe.h"


const int SIZE = 3;

int main() {
    std::srand(std::time(0));
    std::vector<std::vector<char>> board(SIZE, std::vector<char>(SIZE, ' '));
    bool game_over = false;
    bool human_turn = true;

    printBoard(board);

    while (!game_over) {
        if (human_turn) {
            game_over = makeHumanMove(board);
        } else {
            game_over = makeComputerMove(board);
        }

        printBoard(board);
        human_turn = !human_turn;
    }

    if (checkWin(board, 'X')) {
        std::cout << "Congratulations! You won!\n";
    } else if (checkWin(board, 'O')) {
        std::cout << "The computer won! Better luck next time.\n";
    } else {
        std::cout << "It's a draw!\n";
    }

    return 0;
}

void printBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "  1 2 3\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << i + 1;
        for (int j = 0; j < SIZE; ++j) {
            std::cout << "|" << board[i][j];
        }
        std::cout << "|\n";
        if (i < SIZE - 1) {
            std::cout << "";
        }
    }
    std::cout << std::endl;
}

bool makeHumanMove(std::vector<std::vector<char>>& board) {
    int row, col;
    while (true) {
        std::cout << "Enter row and column (1-3): ";
        std::cin >> row >> col;
        if (row >= 1 && row <= SIZE && col >= 1 && col <= SIZE && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = 'X';
            break;
        } else {
            std::cout << "Invalid move. Please try again.\n";
        }
    }
    if (checkWin(board, 'X')) {
        return true;
    } else if (isDraw(board)) {
        return true;
    }
    return false;
}

bool makeComputerMove(std::vector<std::vector<char>>& board) {
    int row, col;
    while (true) {
        row = std::rand() % SIZE;
        col = std::rand() % SIZE;

        if (board[row][col] == ' ') {
            board[row][col] = 'O';
            break;
        }
    }

    if (checkWin(board, 'O')) {
        return true;
    } else if (isDraw(board)) {
        return true;
    }
    return false;
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

    return false;
}

bool isDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}
