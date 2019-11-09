//
// Created by cherit on 11/2/19.
//

#ifndef PROJECT01_VERTEX_H
#define PROJECT01_VERTEX_H

#include <vector>
#include <string>
#include "../objects/Publisher.h"
#include <map>

using namespace std;
class Vertex {
private:
    string class_name;
    vector<Vertex*> childrens;
    bool is_leaf;
public:
    explicit Vertex(string, bool = false);
    string getClassName();
    vector<Vertex*> getChildrens();
    bool isLeaf();
    void setName(string);
    virtual void addChildren(Vertex *);
    Vertex* findVertex(string);

    virtual Publisher* findObject(string);
    void printStructure(int);

    virtual void printObjects();

    static Vertex* generateStructureTree();
};


#endif //PROJECT01_VERTEX_H
