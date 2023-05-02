#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

const int BOARD_SIZE = 5;
const int MAX_HP = 100;

void print_welcome_message() {
    std::cout << "*****************" << std::endl;
    std::cout << " W      W  EEEEE  L       CCC   OO   MM    MM EEEEE" << std::endl;
    std::cout << " W   W  W  E      L      CC   OO  OO M M  M M E    " << std::endl;
    std::cout << " W  WW  W  EEEEE  L     C     O    O M  MM  M EEEEE" << std::endl;
    std::cout << " W W  W W  E      L      CC   OO  OO M   M  M E    " << std::endl;
    std::cout << " WW    WW  EEEEE  LLLLL   CCC   OO   M      M EEEEE" << std::endl;
    std::cout << "*****************" << std::endl;
    std::cout << std::endl;
}

void print_instructions() {
    std::cout << "Before the game start:" << std::endl;
    std::cout << "1. A simple rules, both players have 25 HP at the beginning." << std::endl;
    std::cout << "2. If player with G element eats a W element which is another player element, its HP will be deducted by -3, if it eats G its HP will add by 3, if it eats W which is not another player element its HP will be deducted by -1, Remember that your max HP is 100" << std::endl;
    std::cout << "3. You can only move Right(R), Left(L), Up(U), Down(D). You cannot move outside the map and you cannot move through other players area for example 122G, if you are player 1 you cannot go to right and eat the G because it is separated by 2 (player 2 area)" << std::endl;
    std::cout << "4. If you want to move from 1 to G in 1GGG, you can say R 3, it means right with additional of 3 coordinates." << std::endl;
    std::cout << std::endl;
}

class Game {
public:
    Game() {
        srand(time(0));
        reset_board();
    }

    void reset_board() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '-';
            }
        }
    }

    void print_board() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    void place_player(char player, int row, int col) {
        board[row][col] = player;
        if (player == '1') {
            hp1 = 25;
        } else if (player == '2') {
            hp2 = 25;
        }
    }

    bool is_valid_move(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            return false;
        }
        if (board[row][col] != '-') {
            return false;
        }
        return true;
    }

    void player_move(char player, char direction, int steps) {
        int row, col;
        find_player(player, row, col);

        int new_row = row;
        int new_col = col;

        if (direction == 'U') {
            new_row -= steps;
        } else if (direction == 'D') {
            new_row += steps;
        } else if (direction == 'L') {
            new_col -= steps;
        } else if (direction == 'R') {
            new_col += steps;
        }

        if (is_valid_move(new_row, new_col)) {
            char old_element = board[new_row][new_col];
            board[row][col] = '-';
            board[new_row][new_col] = player;

            if (player == '1') {
                update_hp(player, old_element);
            } else if (player == '2') {
                update_hp(player, old_element);
            }
        }
    }

    void find_player(char player, int &row, int &col) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == player) {
                    row = i;
                    col = j;
                    return;
                }
            }
        }
    }

    void update_hp(char player, char element) {
        if (player == '1') {
            if (element == 'G') {
                hp1 = std::min(hp1 + 3, MAX_HP);
            } else if (element == 'W') {
                hp1 -= 3;
            } else if (element == '-') {
                hp1 -= 1;
            }
        } else if (player == '2') {
            if (element == 'G') {
                hp2 = std::min(hp2 + 3, MAX_HP);
            } else if (element == 'W') {
                hp2 -= 3;
            } else if (element == '-') {
                hp2 -= 1;
            }
        }
    }

    bool is_game_over() {
        return hp1 <= 0 || hp2 <= 0;
    }

    void print_hp() {
        std::cout << "Player 1 HP: " << hp1 << std::endl;
        std::cout << "Player 2 HP: " << hp2 << std::endl;
        std::cout << std::endl;
    }

private:
    char board[BOARD_SIZE][BOARD_SIZE];
    int hp1;
    int hp2;
};

int main() {
    print_welcome_message();
    print_instructions();

    Game game;
    game.place_player('1', 0, 0);
    game.place_player('2', BOARD_SIZE - 1, BOARD_SIZE - 1);

    // Place G and W elements on the board
    game.place_player('G', 2, 2);
    game.place_player('W', 2, 4);

    game.print_board();

    std::string move;
    while (!game.is_game_over()) {
        // Player 1 move
        std::cout << "Player 1 (U, D, L, R): ";
        std::cin >> move;
        if (move.length() > 1) {
            char direction = move[0];
            int steps = std::stoi(move.substr(1));
            game.player_move('1', direction, steps);
        }

        game.print_board();
        game.print_hp();


        // Computer move
        char directions[] = {'U', 'D', 'L', 'R'};
        int random_direction_index = rand() % 4;
        char computer_direction = directions[random_direction_index];
        int computer_steps = rand() % 3 + 1;
        game.player_move('2', computer_direction, computer_steps);

        game.print_board();
        game.print_hp();
    }

    return 0;
}
