//
// Created by cherit on 11/2/19.
//

#ifndef PROJECT01_LEAF_H
#define PROJECT01_LEAF_H


#include "Vertex.h"
#include "../objects/Object_interface.h"
#include <map>

class Leaf: public Vertex{
private:
    map<string, Object_interface> elements;
    bool isLeaf = true;
    int nextID = 0;
public:
    map<string, Object_interface> getElements();
    void addElement(Object_interface);
    void removeElement(string);
    void printElements();
    void addChildren(Vertex);   //To liść, komunikat
};


#endif //PROJECT01_LEAF_H
