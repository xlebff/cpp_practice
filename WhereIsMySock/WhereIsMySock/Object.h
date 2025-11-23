#pragma once

#include <string>
#include <vector>

/**
* @class Object
* @brief Base class for all interactable objects in game
*
* Represents any object that can be interacted with in the game world.
* Provides basic properties and functionality for all game objects.
* Serves as the base class for specialized object types like Item.
*/
class Object {
public:
    /**
    * @brief Construct a new Object
    * @param name The name of the object
    * @param desc The description of the object
    */
    Object(const std::string& name, const std::string& desc);

    /**
    * @brief Virtual destructor for proper polymorphism
    */
    virtual ~Object() = default;

    /**
    * @brief Get the name of the object
    * @return Object name as string
    */
    std::string getName() const;

    /**
    * @brief Get the description of the object
    * @return Object description as string
    */
    std::string getDesc() const;

    /**
    * @brief Set the description of the object
    * @param newDesc New description for the object
    */
    void setDesc(const std::string& newDesc);

    /**
    * @brief Set the description of the object from C-string
    * @param newDesc New description as C-string
    */
    void setDesc(const char* newDesc);

    /**
    * @brief Compare object with string (compares object name)
    * @param other String to compare with object name
    * @return true if object name equals the string
    */
    bool operator==(const std::string other);

private:
    std::string name;   ///< Name of the object for identification
    std::string desc;   ///< Description of the object for player interaction
};