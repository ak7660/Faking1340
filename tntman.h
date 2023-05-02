#ifndef TNTMAN_H
#define TNTMAN_H

#include <string>
#include <vector>

using namespace std;

class Hangman
{
public:
    Hangman(int difficulty);
    bool play();

private:
    string ans;
    vector<char> alpans;
    vector<char> response;
    int chance;

    char get_user_input(const string &prompt);
};

#endif
