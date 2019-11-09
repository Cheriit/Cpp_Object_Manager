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
    static bool removeName(std::string);
protected:
    std::string name;
public:
    static bool nameExists(std::string);
    Object_interface();
    explicit Object_interface(std::ifstream&);
    virtual void putDetails(std::ofstream&) = 0;
    virtual void printDetails() = 0;
    virtual void update() = 0;
    std::string getName();
    bool setName(std::string);
    ~Object_interface();
    static float readNum(std::ifstream&);
    static void updateStr(std::string, std::string&);
    template <class T>
    static void updateNum(std::string, T&);
};

template <class T>
void Object_interface::updateNum(std::string text, T& target) {
    std::string tmp;
    std::cout << text << ":(" << target << ")" << std::endl;
    getline(std::cin, tmp);
    if(!tmp.empty()) target = stof(tmp);
}

#endif //PROJECT01_OBJECT_INTERFACE_H
