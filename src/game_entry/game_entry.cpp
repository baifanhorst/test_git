/**
 * @file game_entry.cpp
 * @brief Implementation of the GameEntry class.
 */


#include "game_entry/game_entry.h"
#include <string>

// Constructor
GameEntry::GameEntry(const std::string& na, int s): name(na), score(s) {}

// Getter for name
std::string GameEntry::getName() const {
    return name;
}

// Getter for score
int GameEntry::getScore() const {
    return score;
}