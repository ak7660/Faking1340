#ifndef MINIGAME_H
#define MINIGAME_H

#include <vector>
#include <functional>

class MiniGame {
public:
    MiniGame();
    bool play_random_game(); // Changed return type to bool

private:
    std::vector<std::function<bool()>> games; // Updated function signature
    static bool game1(); // Changed return type to bool
    static bool game2(); // Changed return type to bool
    static bool game3(); // Changed return type to bool
    static bool game4(); // Changed return type to bool
    static bool game5(); // Changed return type to bool
    static bool game6(); // Changed return type to bool
    static bool game7(); // Changed return type to bool
    static bool game8(); // Changed return type to bool
    static bool game9(); // Changed return type to bool
    static bool game10(); // Changed return type to bool
    static bool game11(); // Changed return type to bool
    static bool game12(); // Changed return type to bool
    static bool game13(); // Changed return type to bool
    static bool game14(); // Changed return type to bool
    static bool game15(); // Changed return type to bool
};

#endif // MINIGAME_H
