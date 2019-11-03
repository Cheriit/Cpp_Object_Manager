//
// Created by cherit on 11/2/19.
//

#ifndef PROJECT01_VERTEX_H
#define PROJECT01_VERTEX_H

#include <vector>
#include <string>

using namespace std;
class Vertex {
private:
    string class_name;
    vector<Vertex*> childrens;
    bool is_leaf = false;
public:
    string getClassName();
    vector<Vertex*> getChildrens();
    void setName(string);
    void addChildren(Vertex);
    Vertex* findVertex(string);
    void printStructure(int);
};


#endif //PROJECT01_VERTEX_H
