#pragma once

#include <vector>
#include <string>

#include "Object.h"

/**
* @class Room
* @brief Represents a room in the game world
*
* Handles room properties, objects contained within, and navigation between rooms.
* Manages static room data and availability for game progression.
*/
class Room {
public:
    // ==================== Constructor & Destructor ====================

    /**
    * @brief Construct a new Room object
    * @param name The name of the room
    * @param desc Description of the room
    * @param objs Vector of objects initially in the room
    * @param available Whether the room is initially accessible
    */
    Room(const std::string& name,
        const std::string& desc = "",
        const std::vector<Object*> objs = {},
        const bool available = true);

    /**
    * @brief Destroy the Room object and clean up resources
    */
    ~Room();

    // ==================== Static Room Management ====================

    /**
    * @brief Initialize all rooms in the game world
    */
    static void initializeRooms();

    /**
    * @brief Clean up all room resources
    */
    static void cleanup();

    /**
    * @brief Get the current room the player is in
    * @return Pointer to current room
    */
    static Room* getCurrentRoom();

    /**
    * @brief Set the current room
    * @param room Pointer to the new current room
    */
    static void setCurrentRoom(Room* room);

    /**
    * @brief Get a room by its name
    * @param roomName Name of the room to find
    * @return Pointer to room, or nullptr if not found
    */
    static Room* getRoom(const std::string& roomName);

    /**
    * @brief Set availability of room connection
    * @param fromRoom Index of source room
    * @param toRoom Index of destination room
    * @param available Whether the connection is available
    * @return true if successful, false if indices are invalid
    */
    static bool setAvailability(const int fromRoom, const int toRoom, const bool available);

    /**
    * @brief Check if a room is accessible from current room
    * @param roomName Name of the room to check
    * @return true if room is accessible, false otherwise
    */
    static bool isAvailable(const std::string& roomName);

    /**
    * @brief Get all rooms in the game
    * @return Vector of all room pointers
    */
    static std::vector<Room*> getAllRooms();

    /**
    * @brief Get availability status of all rooms from current position
    * @return Vector of boolean availability flags
    */
    static std::vector<bool> getAvailableRooms();

    /**
    * @brief Get names of all accessible rooms from current position
    * @return Vector of room names that are currently accessible
    */
    static std::vector<std::string> getAvailableRoomsNames();

    // ==================== Object Management ====================

    /**
    * @brief Find an object in the room by name
    * @param name Name of the object to find
    * @return Pointer to object, or nullptr if not found
    */
    Object* findObject(const std::string& name);

    /**
    * @brief Add an object to the room
    * @param item Pointer to object to add
    * @return true if added successfully, false otherwise
    */
    bool addObject(Object* item);

    /**
    * @brief Remove an object from the room
    * @param item Pointer to object to remove
    * @return true if removed successfully, false otherwise
    */
    bool removeObject(Object* item);

    /**
    * @brief Get all objects in the room
    * @return Vector of object pointers in the room
    */
    std::vector<Object*> getObjects() const;

    // ==================== Room Properties ====================

    /**
    * @brief Get the room's index in the rooms array
    * @return Room index
    */
    int getIndex() const;

    /**
    * @brief Get the room name
    * @return Room name
    */
    std::string getName() const;

    /**
    * @brief Get the room description
    * @return Room description
    */
    std::string getDesc() const;

    /**
    * @brief Set the room description
    * @param newDesc New description string
    */
    void setDesc(std::string newDesc);

    /**
    * @brief Set the room description from C-string
    * @param newDesc New description as C-string
    */
    void setDesc(const char* newDesc);

    // ==================== Operators ====================

    /**
    * @brief Compare room with string (compares room name)
    * @param other String to compare with room name
    * @return true if room name equals the string
    */
    bool operator==(const std::string other) const;

private:
    // ==================== Instance Members ====================
    int index;                      ///< Index of this room in the rooms array
    std::string name;               ///< Name of the room
    std::string desc;               ///< Description of the room
    std::vector<Object*> objs;      ///< Objects contained in the room

    // ==================== Static Members ====================
    static Room* currentRoom;                ///< Current room where player is located
    static std::vector<Room*> allRooms;      ///< All rooms in the game world
    static std::vector<bool> availableRooms; ///< Availability matrix for room navigation
};
