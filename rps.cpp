// RPS.cpp
#include "rps.h"
#include <iostream>
#include <random>
#include <array>

std::string getPlayerInput()
{
    std::string player;
    std::cout << "your choice (R/P/S): ";
    std::cin >> player;
    while (player != "R" && player != "P" && player != "S")
    {
        std::cout << "invalid input" << std::endl;
        std::cout << "your choice (R/P/S): ";
        std::cin >> player;
    }
    return player;
}

std::string getRandomChoice()
{
    std::array<std::string, 3> choices = {"R", "P", "S"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 2);
    return choices[dist(gen)];
}

bool RPS()
{
    int win = 0, loss = 0;
    std::string computer, player;

    while (win != 2 && loss != 2)
    {
        computer = getRandomChoice();
        player = getPlayerInput();

        std::cout << "enemy choice: " << computer << std::endl;

        if (player == computer)
        {
            std::cout << "draw\nwin: " << win << "\nloss: " << loss << std::endl;
        }

        if ((player == "S" && computer == "P") || (player == "P" && computer == "R") || (player == "R" && computer == "S"))
        {
            win++;
            std::cout << "you win\nwin: " << win << "\nloss: " << loss << std::endl;
        }

        if ((player == "S" && computer == "R") || (player == "P" && computer == "S") || (player == "R" && computer == "P"))
        {
            loss++;
            std::cout << "you loss\nwin: " << win << "\nloss: " << loss << std::endl;
        }
    }

    return win == 2;
}
