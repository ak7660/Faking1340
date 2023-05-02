#include "tntman.h"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

Hangman::Hangman(int difficulty)
{
    const vector<vector<string>> library = {
        {"apple", "orange", "hku", "hello", "world", "phone", "cup", "water", "bag"},
        {"university", "engineering", "python", "computer", "science", "perfume", "calculator", "engineer"},
        {"something", "nothing", "phenomenal", "statistics", "ethnicity", "philosophical", "government", "assignment"}};

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> dist(0, library[difficulty - 1].size() - 1);

    ans = library[difficulty - 1][dist(mt)];
    alpans = vector<char>(ans.begin(), ans.end());
    response = vector<char>(ans.length(), '#');
    chance = 5;
}

bool Hangman::play()
{
    cout << string(response.begin(), response.end()) << endl;

    while (chance != 0 && response != alpans)
    {
        char character = get_user_input("your guess: ");

        auto it = find(alpans.begin(), alpans.end(), character);
        if (it == alpans.end())
        {
            cout << "wrong guess" << endl;
            chance--;
        }
        else
        {
            for (size_t i = 0; i < alpans.size(); ++i)
            {
                if (alpans[i] == character)
                {
                    response[i] = character;
                }
            }
        }

        cout << "     " << string(chance, '-') << "*\n|---|\n|TNT|\n|---|" << endl;
        cout << string(response.begin(), response.end()) << endl;
    }

    if (chance == 0)
    {
        cout << "<BOOOOOM!!!>" << endl;
        return false;
    }

    return true;
}

char Hangman::get_user_input(const string &prompt)
{
    char user_input;
    cout << prompt;
    cin >> user_input;

    while (!isalpha(user_input))
    {
        cout << "invalid input" << endl;
        cout << prompt;
        cin >> user_input;
    }

    return user_input;
}
