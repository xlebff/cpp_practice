#pragma once

#include <vector>
#include "Item.h"
#include "SerialPrint.h"

/**
 * @class Inventory
 * @brief Manages the player's inventory system using Singleton pattern
 *
 * Handles storage, retrieval, and management of items collected by the player.
 * Implements capacity limits and provides inventory display functionality.
 */
class Inventory {
public:
    // ==================== Singleton Pattern ====================

    /**
     * @brief Get the singleton instance of Inventory
     * @return Pointer to the single Inventory instance
     */
    static Inventory* getInstance();

    /**
     * @brief Clean up the singleton instance and all inventory items
     */
    static void cleanup();

    // ==================== Constructor & Destructor ====================

    /**
     * @brief Construct a new Inventory with specified capacity
     * @param capacity Maximum number of items the inventory can hold
     */
    Inventory(const int capacity = 5);

    /**
     * @brief Destroy the Inventory and clean up contained items
     */
    ~Inventory();

    // ==================== Inventory Properties ====================

    /**
     * @brief Get the maximum capacity of the inventory
     * @return Maximum number of items that can be stored
     */
    int getCapacity() const;

    /**
     * @brief Get all items currently in the inventory
     * @return Vector of pointers to all items in inventory
     */
    std::vector<Item*> getItems() const;

    // ==================== Item Management ====================

    /**
     * @brief Add an item to the inventory
     * @param item Pointer to the item to add
     * @return true if item was added successfully, false if inventory is full
     */
    bool addItem(Item* item);

    /**
     * @brief Remove an item from the inventory
     * @param item Pointer to the item to remove
     * @return true if item was removed successfully, false if item not found
     */
    bool removeItem(const Item* item);

    /**
     * @brief Remove all items from the inventory
     * @return true if operation completed successfully
     */
    bool clearItems();

    /**
     * @brief Find an item in inventory by name
     * @param itemName Name of the item to find
     * @return Pointer to the item if found, nullptr otherwise
     */
    Item* getItem(const std::string& itemName) const;

    // ==================== Display Methods ====================

    /**
     * @brief Display the current inventory contents to the console
     *
     * Shows all items in inventory along with capacity information.
     * Used when player executes "show inventory" command.
     */
    void display();

private:
    // ==================== Singleton Instance ====================
    static Inventory* instance;  ///< Singleton instance of the inventory

    // ==================== Inventory State ====================
    const int capacity;          ///< Maximum number of items the inventory can hold
    std::vector<Item*> items;    ///< Collection of items currently in inventory
};