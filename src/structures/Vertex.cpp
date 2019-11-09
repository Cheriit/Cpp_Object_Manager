//
// Created by cherit on 11/2/19.
//

#include <iostream>
#include "Vertex.h"
#include "Leaf.h"

Vertex::Vertex(string _name, bool _is_leaf): class_name(_name), is_leaf(_is_leaf) {}

string Vertex::getClassName() { return this->class_name; }
vector<Vertex *> Vertex::getChildrens() { return this->childrens; }
bool Vertex::isLeaf() { return this->is_leaf; }


void Vertex::setName(string _name) { this->class_name = _name; }

void Vertex::addChildren(Vertex *vertex) { this->childrens.push_back(vertex); }

Vertex *Vertex::findVertex(string name) {
    Vertex* vertex = nullptr;
    if ( name == this->class_name ) return this;
    else
        {
            for (auto & children : this->childrens)\
            {
                vertex = children->findVertex(name);
                if (vertex != nullptr) return vertex;
            }
            return nullptr;
        }
}

Publisher *Vertex::findObject(string name) {
    Publisher* vertex = nullptr;
    for (auto & children : this->childrens)\
            {
            vertex = children->findObject(name);
            if (vertex != nullptr) return vertex;
        }
        return nullptr;
}

void Vertex::printObjects() {
    for (auto & children : this->childrens)\
        children->printObjects();
}

void Vertex::printStructure(int depth) {
    for (int i = 0; i < depth; i++)
        cout << " - ";
    cout << this->class_name << endl;
    for (auto & children : this->childrens)
        children->printStructure(depth+1);
}

Vertex *Vertex::generateStructureTree() {
    Vertex* root = new Vertex("Publisher");
    Vertex* book = new Vertex("Book");
    Vertex* magazine = new Vertex("Magazine");
    Vertex* daily = new Vertex("Daily");
    Vertex* weekly = new Vertex("Weekly");
    Leaf* article = new Leaf("Article");
    root->addChildren(book);
    root->addChildren(magazine);
    book->addChildren(new Leaf("PopularScience"));
    book->addChildren(new Leaf("Bestseller"));
    magazine->addChildren(new Leaf("Monthly"));
    magazine->addChildren(daily);
    magazine->addChildren(weekly);
    daily->addChildren(article);
    weekly->addChildren(article);
    return root;
}
