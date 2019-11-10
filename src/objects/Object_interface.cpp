//
// Created by cherit on 11/3/19.
//

#include <algorithm>
#include <iostream>
#include "Object_interface.h"

std::string Object_interface::getName() { return this->name; }
bool Object_interface::setName(std::string name) {
    if( Object_interface::nameExists(name))
    {
        return false;
    }
    Object_interface::removeName(this->name);
    this->name = name;
    Object_interface::usedNames.push_back(name);
    return true;
}
bool Object_interface::removeName(std::string name) {
    if(!Object_interface::nameExists(name))
        return false;
    Object_interface::usedNames.erase(std::remove(Object_interface::usedNames.begin(), Object_interface::usedNames.end(), name), Object_interface::usedNames.end());
    return true;
}
bool Object_interface::nameExists(std::string name) {
    return std::find(Object_interface::usedNames.begin(), Object_interface::usedNames.end(), name) != Object_interface::usedNames.end();
}

Object_interface::~Object_interface() {
    Object_interface::removeName(this->name);
}
std::vector<std::string> Object_interface::usedNames;


std::ostream& operator<<(std::ostream &output, const Object_interface& obj) {
    output << obj.name;
    return output;
}



