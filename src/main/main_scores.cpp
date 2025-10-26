#include <iostream>
#include "game_entry/game_entry.h"
#include "scores/scores.h"


int main() {
    
    Scores scores(3);
    scores.add(GameEntry("Alice", 150));
    scores.add(GameEntry("Bob", 200));
    scores.add(GameEntry("Charlie", 120));
    scores.add(GameEntry("Diana", 50));
    scores.remove(2);

    std::cout << "Maximum entries allowed: " << scores.get_max_entries() << std::endl;
    std::cout << "Number of current entries: " << scores.get_num_entries() << std::endl;
    // std::cout << "The first entry" << scores.entries_[0].getName() << std::endl;
    GameEntry last_entry = scores.getEntry(scores.get_num_entries() - 1);
    std::cout << "Last entry - Player: " << last_entry.getName() << ", Score: " << last_entry.getScore() << std::endl;

    return EXIT_SUCCESS;
}   