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
    /**
     * Creates Leaf object
     */
    explicit Leaf(string);
    /**
     * Returns map of all leaf's vertexes
     * @return map
     */
    map<string, Publisher*> getElements();
    /**
     * Adds object to a leaf
     * @param Publisher* object to add
     */
    void addElement(Publisher*);
    /**
     * Removes object from a leaf based on name, deletes object
     * @param string object's name
     */
    void removeElement(string);
    /**
     * Prints all leaf's objects short version
     */
    void printObjects() override ;
    /**
     * Adds object to leaf
     * @param Vertex* object
     */
    void addChildren(Vertex* ) override;
    /**
     * Looking for a Object with a given name
     * @param string obj name
     * @return Publisher* object instance
     */
    Publisher * findObject(string) override;
};


#endif //PROJECT01_LEAF_H
