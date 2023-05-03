#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <functional>
#include "minigame.h"

MiniGame::MiniGame() {
    games.push_back(&game1);
    games.push_back(&game2);
    games.push_back(&game5);
    games.push_back(&game6);
    games.push_back(&game7);
    games.push_back(&game8);
    games.push_back(&game9);
    games.push_back(&game10);
    games.push_back(&game11);
    games.push_back(&game12);
    games.push_back(&game13);
    games.push_back(&game14);
    games.push_back(&game15);
    std::srand(std::time(0));
}
bool MiniGame::play_random_game() {
    int random_index = std::rand() % games.size();
    bool result = games[random_index]();
    std::cout << "\nPress Enter to return to the maze...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return result;
}


//escape from lion
bool MiniGame::game1() {
    std::cout << "Mini game 1: Adventure - Escape the lion villain's territory!\n";
    std::string choice;

    while (true) {
        std::cout << "You have three choices:\n";
        std::cout << "1. Go left\n";
        std::cout << "2. Go right\n";
        std::cout << "3. Charge forward\n";
        std::cout << "Please enter your choice (1/2/3): ";
        std::cin >> choice;

        if (choice == "1") {
            while (true) {
                std::cout << "You go left and find a hidden passageway. Do you want to enter it? (y/n): ";
                std::cin >> choice;
                if (choice == "y" || choice == "Y") {
                    std::cout << "You enter the hidden passageway and find a secret exit.\n";
                    return true;
                } else if (choice == "n" || choice == "N") {
                    std::cout << "You decide not to enter the hidden passageway and continue walking forward.\n";
                    break;
                } else {
                    std::cout << "Invalid choice! Please try again.\n";
                }
            }
        } else if (choice == "2") {
            std::cout << "You go right and encounter the minions of the lion villain. You've been discovered!\n";
            return false;
        } else if (choice == "3") {
            std::cout << "You bravely charge forward, breaking through the lion villain's defenses!\n";
            return true;
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }
}

// Trivial quiz
bool MiniGame::game2() {
    std::string question = "Which planet is the third from the Sun in our solar system?\n"
                           "A) Mars\n"
                           "B) Venus\n"
                           "C) Earth\n"
                           "D) Mercury\n";

    std::string correctAnswer = "C";
    std::string userAnswer;

    std::cout << "Mini game 2: Answer the following question:\n";
    std::cout << question << std::endl;
    std::cout << "Enter your answer (A, B, C, or D): \n";
    std::cin>>userAnswer;

    if (userAnswer == correctAnswer) {
        std::cout<<"Congrats you are right continue the game..."<<std::endl;
        return true;
    } 
    else {
        std::cout<<"Just a pity, you are incorrect"<<std::endl;
        return false;
    }
}

// Trivial quiz
bool MiniGame::game3() {
    std::cout << "Mini game 3: Trivia Quiz\n";
    std::string choice;

    std::cout << "Welcome to the trivia quiz! Please answer the following question:\n";
    std::cout << "What is the capital of France?\n";
    std::cout << "1. London\n";
    std::cout << "2. Berlin\n";
    std::cout << "3. Paris\n";
    std::cout << "4. Rome\n";
    std::cout << "Please enter the number of your choice (1/2/3/4): ";
    std::cin >> choice;

    if (choice == "3") {
        std::cout<<"Congrats you are right continue the game..."<<std::endl;
        return true;
    } 
    else {
        std::cout<<"Just a pity, you are incorrect"<<std::endl;
        return false;
    }
}

bool MiniGame::game4() {
    std::cout << "Mini game 4: Animal Trivia\n";
    std::string choice;

    std::cout << "Welcome to the Animal Trivia!\n";
    std::cout << "Here's the question:\n";
    std::cout << "Which of these animals is a mammal?\n";
    std::cout << "1. Eagle\n";
    std::cout << "2. Shark\n";
    std::cout << "3. Platypus\n";
    std::cout << "4. Snake\n";

    while (true) {
        std::cout << "Please enter your choice (1/2/3/4): ";
        std::cin >> choice;

        if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
            break;
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    if (choice == "3") {
        std::cout<<"Congrats you are right continue the game..."<<std::endl;
        return true;
    } else {
        std::cout<<"Just a pity, you are incorrect"<<std::endl;
        return false;
    }
}
// Geography quiz
bool MiniGame::game5() {
    std::cout << "Mini game 5: Geography Quiz\n";
    std::string choice;

    std::cout << "Welcome to the Geography Quiz!\n";
    std::cout << "Here's the question:\n";
    std::cout << "Which of these countries has the largest population?\n";
    std::cout << "1. United States\n";
    std::cout << "2. India\n";
    std::cout << "3. China\n";
    std::cout << "4. Brazil\n";

    while (true) {
        std::cout << "Please enter your choice (1/2/3/4): ";
        std::cin >> choice;

        if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
            break;
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    if (choice == "3") {
        std::cout<<"Congrats you are right continue the game..."<<std::endl;
        return true;
    } else {
        std::cout<<"Just a pity, you are incorrect"<<std::endl;
        return false;
    }
}

// Science quiz
bool MiniGame::game6() {
    std::cout << "Mini game 6: Science Quiz\n";
    std::string choice;

    std::cout << "Welcome to the Science Quiz!\n";
    std::cout << "Here's the question:\n";
    std::cout << "What is the chemical symbol for water?\n";
    std::cout << "1. H2O\n";
    std::cout << "2. NaCl\n";
    std::cout << "3. CO2\n";
    std::cout << "4. O2\n";

    while (true) {
        std::cout << "Please enter your choice (1/2/3/4): ";
        std::cin >> choice;

        if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
            break;
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    if (choice == "1") {
        std::cout<<"Congrats you are right continue the game..."<<std::endl;
        return true;
    } else {
        std::cout<<"Just a pity, you are incorrect"<<std::endl;
        return false;
    }
}

// History quiz
bool MiniGame::game7() {
    std::cout << "Mini game 7: History Quiz\n";
    std::string choice;

    std::cout << "Welcome to the History Quiz!\n";
    std::cout << "Here's the question:\n";
    std::cout << "Who was the first president of the United States?\n";
    std::cout << "1. Abraham Lincoln\n";
    std::cout << "2. George Washington\n";
    std::cout << "3. Thomas Jefferson\n";
    std::cout << "4. John Adams\n";

    while (true) {
        std::cout << "Please enter your choice (1/2/3/4): ";
        std::cin >> choice;

        if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
            break;
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    if (choice == "2") {
        std::cout << "Congrats! You are right. George Washington was the first president of the United States. Continue the game...\n";
        return true;
    } else {
        std::cout << "Just a pity, you are incorrect. George Washington was the first president of the United States. Better luck next time!\n";
        return false;
    }
}

bool MiniGame::game8() {
    std::cout << "Mini game 8: Music Quiz\n";
    std::string choice;

    std::cout << "Welcome to the Music Quiz!\n";
    std::cout << "Here's the question:\n";
    std::cout << "Which of these instruments belongs to the string family?\n";
    std::cout << "1. Piano\n";
    std::cout << "2. Saxophone\n";
    std::cout << "3. Trumpet\n";
    std::cout << "4. Flute\n";

    while (true) {
        std::cout << "Please enter your choice (1/2/3/4): ";
        std::cin >> choice;

        if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
            break;
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    if (choice == "1") {
        std::cout << "Congrats! You are right. The piano belongs to the string family. Continue the game...\n";
        return true;
    } else {
        std::cout << "Just a pity, you are incorrect. The piano belongs to the string family. Better luck next time!\n";
        return false;
    }
}

// Jumanji Adventure
bool MiniGame::game9() {
    std::cout << "Mini game 9: Jumanji Adventure\n";
    std::string choice;

    std::cout << "Welcome to the Jumanji Adventure!\n";
    std::cout << "You are in a dense jungle surrounded by wild animals.\n";
    std::cout << "You must choose the correct path to continue your journey.\n";
    std::cout << "Which path will you choose?\n";
    std::cout << "1. Follow the river\n";
    std::cout << "2. Climb the nearest tree\n";
    std::cout << "3. Walk deeper into the jungle\n";
    std::cout << "4. Run back the way you came\n";

    while (true) {
        std::cout << "Please enter your choice (1/2/3/4): ";
        std::cin >> choice;

        if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
            break;
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    if (choice == "1") {
        std::cout << "Congrats! Following the river, you find a hidden cave containing a map to safety.\n";
        std::cout << "Continue the game..."<<std::endl;
        return true;
    } else {
        std::cout << "Just a pity, your choice led you to a dangerous encounter!\n";
        std::cout << "Try again to find the correct path.\n";
        return false;
    }
}

// Treasure Hunt
bool MiniGame::game10() {
    std::cout << "Mini game 10: Treasure Hunt\n";
    std::string choice;

    std::cout << "Welcome to the Treasure Hunt!\n";
    std::cout << "You are on a mysterious island searching for a lost treasure.\n";
    std::cout << "To find the treasure, you must answer a riddle correctly.\n";
    std::cout << "Here's the riddle:\n";
    std::cout << "The more you take, the more you leave behind. What am I?\n";
    std::cout << "1. Time\n";
    std::cout << "2. Footsteps\n";
    std::cout << "3. Memories\n";
    std::cout << "4. Shadows\n";

    while (true) {
        std::cout << "Please enter your choice (1/2/3/4): ";
        std::cin >> choice;

        if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
            break;
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    if (choice == "2") {
        std::cout << "Congrats! You've solved the riddle, and a secret door opens to reveal the hidden treasure.\n";
        std::cout << "Continue the game..."<<std::endl;
        return true;
    } else {
        std::cout << "Just a pity, your answer was incorrect.\n";
        std::cout << "Try again to solve the riddle and find the treasure.\n";
        return false;
    }
}// Quicksand Escape
bool MiniGame::game11() {
    std::cout << "Mini game 11: Quicksand Escape\n";
    std::string choice;

    std::cout << "Welcome to Quicksand Escape!\n";
    std::cout << "You are trapped in quicksand and must escape before sinking completely.\n";
    std::cout << "Choose the right technique to escape the quicksand.\n";
    std::cout << "1. Swim to the surface\n";
    std::cout << "2. Stay still and call for help\n";
    std::cout << "3. Gently move your legs and lean back\n";
    std::cout << "4. Try to grab a nearby branch\n";

    while (true) {
        std::cout << "Please enter your choice (1/2/3/4): ";
        std::cin >> choice;

        if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
            break;
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    if (choice == "3") {
        std::cout << "Congrats! You've successfully escaped the quicksand and can continue your adventure.\n";
        std::cout << "Continue the game..."<<std::endl;
        return true;
    } else {
        std::cout << "Just a pity, you've sunk deeper into the quicksand.\n";
        std::cout << "Try again to find the correct technique to escape.\n";
        return false;
    }
}

// Ancient Temple Puzzle
bool MiniGame::game12() {
    std::cout << "Mini game 12: Ancient Temple Puzzle\n";
    std::string choice;

    std::cout << "Welcome to the Ancient Temple Puzzle!\n";
    std::cout << "You've entered an ancient temple filled with traps and puzzles.\n";
    std::cout << "To proceed, you must solve the following puzzle:\n";
    std::cout << "Arrange the numbers 1 to 9 in a 3x3 grid so that the sum of each row, column, and diagonal is the same.\n";
    std::cout << "Which number should be placed in the center of the grid?\n";
    std::cout << "1. 1\n";
    std::cout << "2. 5\n";
    std::cout << "3. 9\n";
    std::cout << "4. 6\n";

    while (true) {
        std::cout << "Please enter your choice (1/2/3/4): ";
        std::cin >> choice;

        if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
            break;
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    if (choice == "2") {
        std::cout << "Congrats! You've solved the puzzle, and a secret passage opens to let you continue your adventure.\n";
        std::cout << "Continue the game..."<<std::endl;
        return true;
    } else {
        std::cout << "Just a pity, the incorrect placement sets off a trap!\n";
        std::cout << "Try again to find the correct number for the center of the grid.\n";
        return false;
    }
}
// Wild Animal Encounter
bool MiniGame::game13() {
    std::cout << "Mini game 13: Wild Animal Encounter\n";
    std::string choice;

    std::cout << "Welcome to the Wild Animal Encounter!\n";
    std::cout << "While exploring the jungle, you come face to face with a ferocious tiger.\n";
    std::cout << "To survive, you must choose the best course of action.\n";
    std::cout << "1. Try to scare the tiger away by shouting and waving your arms\n";
    std::cout << "2. Slowly back away while maintaining eye contact\n";
    std::cout << "3. Lie down and play dead\n";
    std::cout << "4. Climb the nearest tree\n";

    while (true) {
        std::cout << "Please enter your choice (1/2/3/4): ";
        std::cin >> choice;

        if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
            break;
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    if (choice == "2") {
        std::cout << "Congrats! You've successfully avoided the tiger and can continue your adventure.\n";
        std::cout << "Continue the game..."<<std::endl;
        return true;
    } else {
        std::cout << "Just a pity, the tiger attacked, and your adventure ends here.\n";
        std::cout << "Try again to find the best course of action.\n";
        return false;
    }
}

// Raging River Crossing
bool MiniGame::game14() {
    std::cout << "Mini game 14: Raging River Crossing\n";
    std::string choice;

    std::cout << "Welcome to the Raging River Crossing!\n";
    std::cout << "You must cross a raging river to continue your adventure.\n";
    std::cout << "Choose the best way to cross the river.\n";
    std::cout << "1. Swim across\n";
    std::cout << "2. Build a makeshift raft\n";
    std::cout << "3. Find a nearby bridge\n";
    std::cout << "4. Use a zipline across the river\n";

    while (true) {
        std::cout << "Please enter your choice (1/2/3/4): ";
        std::cin >> choice;

        if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
            break;
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    if (choice == "3") {
        std::cout << "Congrats! You've found a bridge and safely crossed the river, continuing your adventure.\n";
        std::cout << "Continue the game..."<<std::endl;
        return true;
    } else {
        std::cout << "Just a pity, your chosen method failed, and you got swept away by the current.\n";
        std::cout << "Try again to find the safest way to cross the river.\n";
        return false;
    }
}// Abandoned Village Mystery
bool MiniGame::game15() {
    std::cout << "Mini game 15: Abandoned Village Mystery\n";
    std::string choice;

    std::cout << "Welcome to the Abandoned Village Mystery!\n";
    std::cout << "You've stumbled upon an abandoned village, and to proceed with your adventure, you must uncover the reason behind its desertion.\n";
    std::cout << "Choose the most likely cause of the village's abandonment.\n";
    std::cout << "1. A sudden natural disaster\n";
    std::cout << "2. A mysterious illness\n";
    std::cout << "3. A powerful curse\n";
    std::cout << "4. A dangerous predator\n";

    while (true) {
        std::cout << "Please enter your choice (1/2/3/4): ";
        std::cin >> choice;

        if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
            break;
        } else {
            std::cout << "Invalid choice! Please try again.\n";
        }
    }

    if (choice == "3") {
        std::cout << "Congrats! You've discovered that the village was abandoned due to a powerful curse.\n";
        std::cout << "By solving the mystery, you've lifted the curse and can safely continue your adventure.\n";
        std::cout << "Continue the game..." << std::endl;
        return true;
    } else {
        std::cout << "Just a pity, your investigation led you to a dead end, and the village remains shrouded in mystery.\n";
        std::cout << "Try again to uncover the true reason behind the village's abandonment.\n";
        return false;
    }
}

