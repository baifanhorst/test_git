#include "scores/scores.h"
#include <stdexcept>
#include <iostream>

Scores::Scores(int max_entries)
    : max_entries_(max_entries), num_entries_(0) {
    // This constructor sets the maximum number of entries and initializes the current number of entries to zero.
    // It also allocates memory for storing the entries.
    entries_ = new GameEntry[max_entries_];
}   

Scores::~Scores() {
    // Destructor to free the allocated memory
    delete[] entries_;
}

int Scores::get_num_entries() const {
    return num_entries_;
}

int Scores::get_max_entries() const {
    return max_entries_;
}

void Scores::add(const GameEntry& e) {
    // This implementation is very tricky.
    // Basically, there are three cases:
    // (1) The entry is full, and the new score is not higher than the last (the lowest) entry
    // (2) The entry is full, but the new score is higher than the last entry.
    // (3) The entry is not full.
    // If the entry is not full, the input entry is always added, so the number of entries increases by 1.
    // In case (1), nothing needs to be done.
    // In case (2) and (3), we need to find the correct position for the new entry and insert it there.
    // The inserting operation in these two cases follows the same logic.
    // For insertion in case (2), since the last entry is already checked, we only need to start from the second from the last entry, whose index is num_entries_ - 2.
    // For insertion in case (3), we start from the last entry.
    // However, since the number of entries increases by 1 in case (3) before comparison, the index of the original last entry is num_entries_ - 2.
    // Therefore, we start from index num_entries_ - 2 in both cases.
    // This implies a unified implementation for both cases.

    // Get the score of the new entry
    int new_score = e.getScore();
    // Check if the entry is full
    if (num_entries_ == max_entries_) {
        // If full, check if the new score is higher than the last entry
        if (new_score <= entries_[max_entries_ - 1].getScore()) {
            std :: cout << "No insertion" << std :: endl;
            return;
        }
        // If the new score is higher, we will replace the last entry later. No action here.
    }
    // If not full, insertion will always be performed.
    // So we increase the number of entries by 1.
    else num_entries_++;

    // Get the index of the first entry to be compared.
    int i = num_entries_ - 2;
    // If the index is still valid and a higher score has not been found 
    while (i >= 0 && entries_[i].getScore() < new_score) {
        // Shift the entry to the right
        entries_[i + 1] = entries_[i];
        // Move to the previous index
        i--;
    }
    // Insert the new entry at the correct position
    // Since we do not define the assignment operator for GameEntry, the default one is used here.
    // The default assignment operator performs a member-wise shallow copy.
    // This is sufficient since GameEntry only contains a string and an int.
    entries_[i + 1] = e;

    std :: cout << "Entry added" << std :: endl;
}   



GameEntry Scores::remove(int index) {
    // Check for valid index
    if (index < 0 || index >= num_entries_) {
        throw std::out_of_range("Index out of range");
    }
    // Store the entry to be removed
    GameEntry removed_entry = entries_[index];
    // Shift entries to fill the gap
    // i represents the index of the target position to be filled
    // i ranges from index to the second last entry, whose index is num_entries_ - 2
    for (int i = index; i <= num_entries_ - 2; i++) {
        // Shifting the entry by the default shallow copy assignment
        entries_[i] = entries_[i + 1];
    }
    // Decrease the number of entries
    num_entries_--;
    // Return the removed entry
    std :: cout << "Entry removed" << std :: endl;
    return removed_entry;
}   



const GameEntry& Scores::getEntry(int index) const {
    // Check for valid index
    if (index < 0 || index >= num_entries_) {
        throw std::out_of_range("Index out of range");
    }
    return entries_[index];
}