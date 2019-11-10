//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_OBJECT_INTERFACE_H
#define PROJECT01_OBJECT_INTERFACE_H

#include <string>
#include <vector>
#include <fstream>

class Object_interface {
private:
    static std::vector<std::string> usedNames;
    /**
     * Removes name from a static table
     * @return bool
     */
    static bool removeName(std::string);
protected:
    std::string name;
public:
    /**
     * Save object data into a file
     * @param ofstream& files stream
     */
    virtual void putDetails(std::ofstream&) = 0;
    /**
     * Prints object's data
     */
    virtual void printDetails() = 0;
    /**
     * Updates objects content interacting with the user
     */
    virtual void update() = 0;
    /**
     * Get object's unique name
     * @return string
     */
    std::string getName();
    /**
     * Set object's unique name, 0 if it's not unique
     * @return bool
     */
    bool setName(std::string);
    /**
     * Static, check if name already exists
     * @return bool
     */
    static bool nameExists(std::string);
    /**
     * Overloads operator, printing object's name
     * @param output stream
     * @param article object
     * @return ostream&
     */
    friend std::ostream& operator<<(std::ostream& output, const Object_interface& article);
    /**
     * Destroys object instance
     */
    ~Object_interface();
};


#endif //PROJECT01_OBJECT_INTERFACE_H
