//
// Created by cherit on 11/2/19.
//

#include <iostream>
#include "Leaf.h"

Leaf::Leaf(string _name): Vertex(_name, true) {}
map<string, Publisher *> Leaf::getElements() { return this->elements; }

void Leaf::addElement(Publisher* obj) { this->elements.insert(pair<string, Publisher*>(obj->getName(), obj)); }

void Leaf::removeElement(string name) {
    Publisher* objToRemove = this->findObject(name);
    if ( this->elements.erase(name) )
    {
        delete(objToRemove);
        cout << "Succesfully deleted element with name " << name << endl;
    }
    else
        cout << "There's no element with name " << name << endl;
}

void Leaf::printObjects() {
    map<string, Publisher*>::iterator it;
    cout << this->getClassName() << endl;
    for ( it = this->elements.begin(); it != this->elements.end(); it++ )
    {
        std::cout << "\t" << it->first << endl;
    }

}

Publisher * Leaf::findObject(string name) {
    map<string, Publisher*>::iterator it;
    for ( it = this->elements.begin(); it != this->elements.end(); it++ )
    {
        if( it->first == name ) return it->second;
    }
    return nullptr;
}

void Leaf::addChildren(Vertex*) {}

