//
// Created by cherit on 11/3/19.
//

#include "Object_interface.h"

string Object_interface::getName() { return this->name; }
void Object_interface::setName(string class_name, int id) { this->name = name+(string)id; }
void Object_interface::setName(string name) { this->name = name; }