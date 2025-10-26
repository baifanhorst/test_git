#include <iostream>
#include "game_entry/game_entry.h"

int main() {
    GameEntry entry("Alice", 150);
    std::cout << "Player: " << entry.getName() << ", Score: " << entry.getScore() << std::endl;
    return 0;
}   