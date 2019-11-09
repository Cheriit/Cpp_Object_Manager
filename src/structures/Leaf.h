//
// Created by cherit on 11/2/19.
//

#ifndef PROJECT01_LEAF_H
#define PROJECT01_LEAF_H


#include "Vertex.h"
#include "../objects/Publisher.h"
#include <map>

class Leaf: public Vertex{
private:
    map<string, Publisher*> elements;
    bool isLeaf = true;
public:
    explicit Leaf(string);
    map<string, Publisher*> getElements();
    void addElement(Publisher*);
    void removeElement(string);
    void printObjects() override ;
    void addChildren(Vertex* ) override;
    Publisher * findObject(string) override;
};


#endif //PROJECT01_LEAF_H
