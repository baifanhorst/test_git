/**
 * @file scores.h
 * @brief Declaration of the Scores class.
 */


#include "game_entry/game_entry.h"

/**
 * @class Scores
 * @brief Manages a list of high scores for game entries.
 */
class Scores {
public:
    /** @name Class member functions */
    ///@{

    /**
     * @brief Constructs a Scores object given a maximum number of entries.
     * @param max_entries The maximum number of entries allowed. Default maximum number of entries is 10.
     * @details This constructor initializes the maximum number of entries according to the input and intializes the current number of entries to be zero.
     * It also allocates memory for storing the entries.
     */
    Scores(int max_entries = 10);
    /**
     * @brief Destructor to free the allocated memory.
     */
    ~Scores();

    /**
     * @brief Gets the current number of entries.
     * @return The current number of entries.
     */
    int get_num_entries() const;

    /**
     * @brief Gets the maximum number of entries.
     * @return The maximum number of entries.   
     */
    int get_max_entries() const;

    /**
     * @brief Adds a new game entry to the scores list.
     * @param e The game entry to be added.
     * @details This method adds a new game entry to the scores list if it qualifies to be in the top scores.
     * If the scores list is full and the new entry's score is not higher than the lowest score in the list, it will not be added.
     * If the new entry qualifies, it will be inserted in the correct position to maintain the order of scores.
     * This function natuarally gives a descending order of scores.
     */
    void add(const GameEntry& e);

    /**
     * @brief Removes the game entry at the specified index.
     * @param index The index of the entry to be removed.
     * @return The removed game entry.
     * @throws std::out_of_range if the index is invalid.
     * @details This method removes the game entry at the specified index and shifts subsequent entries to fill the gap.
     */
    GameEntry remove(int index);  
    
    /**
     * @brief Gets the game entry at the specified index.
     * @param index The index of the entry to retrieve.
     * @return The game entry at the specified index.
     * @throws std::out_of_range if the index is invalid.
     */
    const GameEntry& getEntry(int index) const;

    ///@}
    
private:
    /** @name Class variables */
    ///@{

    /**
     * @brief Maximum number of entries allowed.
     */
    int max_entries_; 
    /**
     * @brief Current number of entries.
     */
    int num_entries_; 
    /**
     * @brief Dynamic array to store the game entries.  
     */
    GameEntry* entries_; 

    ///@}
};