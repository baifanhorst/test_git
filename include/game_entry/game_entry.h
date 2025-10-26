/**
 * @file game_entry.h
 * @brief Declaration of the GameEntry class.
 */


#ifndef GAME_ENTRY_H_
#define GAME_ENTRY_H_

#include <string>


/**
 * @class GameEntry
 * @brief Represents a game entry with a player's name and score.
 */
class GameEntry {
    private:    
    /** @name Class variables */
    ///@{

    /// Name of the player.
    std::string name; 
    /// Score of the player.
    int score; 

    ///@}

    public:
    /** @name Class member functions */
    ///@{

    /**
     * @brief Constructs a GameEntry object with the given name and score.
     * @param na The name of the player.
     * @param s The score of the player.
     */
    // const std::string&: reference to a constant string to avoid copying and modifying
    GameEntry(const std::string& na = "", int s = 0);
    
    /**
     * @brief Gets the name of the player.
     * @return The name of the player.
     */
    std::string getName() const; // const: indicates that this method does not modify the object
    /**
     * @brief Gets the score of the player.
     * @return The score of the player.
     */
    int getScore() const;

    ///@}
};


#endif // GAME_ENTRY_H_