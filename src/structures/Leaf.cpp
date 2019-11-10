//
// Created by cherit on 11/2/19.
//

#include <iostream>
#include "Leaf.h"
#include "../objects/Article.h"
#include "../objects/Bestseller.h"
#include "../objects/Monthly.h"
#include "../objects/PopularScience.h"

Leaf::Leaf(string _name): Vertex(_name, true) {}
map<string, Publisher *> Leaf::getElements() { return this->elements; }

void Leaf::addElement(Publisher* obj) { this->elements.insert(pair<string, Publisher*>(obj->getName(), obj)); }

void Leaf::removeElement(string name) {
    if ( this->getClassName() == "Article" )
    {
        Article* obj = dynamic_cast<Article*>(this->findObject(name));
        delete obj;
    }
    else if ( this->getClassName() == "Bestseller" )
    {
        Bestseller* obj = dynamic_cast<Bestseller*>(this->findObject(name));
        delete obj;

    }
    else if ( this->getClassName() == "Monthly" )
    {
        Monthly* obj = dynamic_cast<Monthly*>(this->findObject(name));
        delete obj;
    }
    else if ( this->getClassName() == "PopularScience" )
    {
        PopularScience* obj = dynamic_cast<PopularScience*>(this->findObject(name));
        delete obj;
    }
    if ( this->elements.erase(name) )
    {
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
        std::cout << "\t" << it->first;
        std::cout << endl;
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

