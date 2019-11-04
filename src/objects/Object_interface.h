//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_OBJECT_INTERFACE_H
#define PROJECT01_OBJECT_INTERFACE_H

#include <string>

using namespace std;
class Object_interface {
protected:
    string name;
public:
    virtual void putDetails(ofstream&) = 0;
    virtual void printDetails() = 0;
    virtual void update() = 0;
    string getName();
    void setName(string);
    void setName(string, int);
};


#endif //PROJECT01_OBJECT_INTERFACE_H
