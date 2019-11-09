//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_OBJECT_INTERFACE_H
#define PROJECT01_OBJECT_INTERFACE_H

#include <string>
#include <vector>

class Object_interface {
private:
    static std::vector<std::string> usedNames;
    static bool nameExists(std::string);
    static bool removeName(std::string);
protected:
    std::string name;
public:
    Object_interface();
    explicit Object_interface(std::ifstream&);
    virtual void putDetails(std::ofstream&) = 0;
    virtual void printDetails() = 0;
    virtual void update() = 0;
    std::string getName();
    bool setName(std::string);
    ~Object_interface();
};

#endif //PROJECT01_OBJECT_INTERFACE_H
