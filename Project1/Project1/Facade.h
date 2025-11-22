#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Room.h"
#include "Inventory.h"
#include "Item.h"
#include "Object.h"
#include "UsageManager.h"
#include "CombineManager.h"

/**
 * @class Facade
 * @brief The main class is a facade for controlling game logic
 *
 * Implements the Singleton pattern to provide a single instance
 * Handles user input and delegates execution to commands
 */
class Facade {
public:
    // ==================== Singleton Pattern ====================

    /**
     * @brief Get a single instance of the Facade class
     * @return Pointer to a single instance of Facade
     */
    static Facade* getInstance();

    // ==================== Game Flow Methods ====================

    /**
     * @brief Processing user input
     * @param input A string entered by the user, converted to the desired format
     * @return true if the command implies further execution of the program, false if not
     *
     * Reads the action from the entered string.
     * If successful, it goes through all available actions.
     * If the result is a full-fledged working team, it increases the command counter.
     */
    bool processInput(std::string& input);

    /**
     * @brief Welcome message output
     */
    void showWelcome();

    /**
     * @brief Display help information about available commands
     */
    void showHelp();

    /**
     * @brief End the game and display final message
     */
    void endGame();

    // ==================== Game State Methods ====================

    /**
     * @brief Get current number of turns
     * @return Current number of turns
     */
    int getTurns();

    /**
     * @brief Get maximum number of turns
     * @return Maximum number of turns in the game
     */
    int getMaxTurns();

    /**
     * @brief Check conditions for true game ending
     * @return true if true ending conditions are met
     */
    bool trueEnding();

    // ==================== Player Actions ====================

    /**
     * @brief Move to the specified room
     * @param roomName Name of the room to move to
     * @return true if movement successful, false if room is not accessible
     */
    bool moveTo(const std::string& roomName);

    /**
     * @brief Take item from current room
     * @param itemName Name of the item to take
     * @return true if item taken successfully, false if item is not available
     */
    bool takeItem(const std::string& itemName);

    /**
     * @brief Drop item from inventory
     * @param itemName Name of the item to drop
     * @return true if item dropped successfully, false if item not in inventory
     */
    bool dropItem(const std::string& itemName);

    /**
     * @brief Use item with specified arguments
     * @param args Vector of strings with command arguments
     * @return true if usage successful, false in case of error
     */
    bool useItem(std::vector<std::string> args);

    /**
     * @brief Combine multiple items
     * @param args Vector of strings with item names to combine
     * @return true if combination successful, false in case of error
     */
    bool combineItems(std::vector<std::string> args);

    /**
     * @brief Inspect an object or character
     * @param objectName Name of the object to inspect
     * @return true if object exists and inspected, false otherwise
     */
    bool inspect(const std::string& objectName);

    /**
     * @brief Show player's inventory contents
     */
    void showInventory();

    /**
     * @brief Show description of current room and its contents
     */
    void lookAround();

private:
    // ==================== Singleton Instance ====================
    static Facade* instance;

    // ==================== Private Constructor ====================
    /**
     * @brief Private constructor (Singleton pattern)
     * @params maxTurns Maximum number of moves
     * @params maxLightTurns The life span of a phone with a flashlight on
     */
    Facade(const int maxTurns = 50, const int maxLightTurns = 10);

    // ==================== Game State Variables ====================
    int maxTurns;           ///< Maximum number of turns in the game
    int turns;              ///< Current number of turns
    int lightTurns;         ///< Number of turns with light source active
    int maxLightTurns;      ///< Maximum number of turns with light source

    // ==================== Input Processing ====================

    /**
     * @brief Parse user input into command and arguments
     * @param input Input string from user
     * @param action[out] Extracted command
     * @param args[out] Vector of command arguments
     * @return true if parsing successful, false in case of parsing error
     */
    bool parseInput(std::string& input,
        std::string& action,
        std::vector<std::string>& args);

    /**
     * @brief Combine arguments into single string
     * @param args Vector of string arguments
     * @return Combined string of arguments
     */
    std::string combineArgs(const std::vector<std::string>& args);

    /**
     * @brief Check if string is a valid command
     * @param curCmd String to check
     * @return true if command is valid, false otherwise
     */
    bool isCommand(std::string& curCmd);

    // ==================== Turn Management ====================

    /**
     * @brief Update turn counter and check game conditions
     * @return Current number of turns after update
     *
     * Increases turn counter, updates light source status,
     * and checks for game ending conditions
     */
    int updateTurns();
};