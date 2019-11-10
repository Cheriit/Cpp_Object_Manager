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
/**
 * Graph's vertex
 *
 * Allows to manipulate structure and data processing
 */
class Vertex {
private:
    string class_name;
    vector<Vertex*> childrens;
    bool is_leaf;
public:
    /**
     * Creates Vertex with a given name
     */
    explicit Vertex(string, bool = false);
    /**
     * Returns vertex's representing class name
     * @return string class name
     */
    string getClassName();
    /**
     * Return all connected vertexes
     * @return vector<Vertex*> connected vertexes
     */
    vector<Vertex*> getChildrens();
    /**
     * Shows us if vertex is a leaf
     * @return bool is a leaf
     */
    bool isLeaf();
    /**
     * Sets class name
     * @param string name
     */
    void setName(string);
    /**
     * Appends new, connected vertex
     * @param Vertex*
     */
    virtual void addChildren(Vertex *);
    /**
     * Searching vertex with a giben name - recursive
     * @param string searching name
     * @return Vertex*
     */
    Vertex* findVertex(string);

    /**
     * Searching object with a given name - recursive
     * @param string searching name
     * @return Publisher*
     */
    virtual Publisher* findObject(string);
    /**
     * Recursive print of a project's structure
     */
    void printStructure(int);
    /**
     * Recursive printing all objects in leafes
     */
    virtual void printObjects();
    /**
     * Static function creating project's graph structure
     * @return Vertex* rootVertex
     */
    static Vertex* generateStructureTree();
};


#endif //PROJECT01_VERTEX_H
