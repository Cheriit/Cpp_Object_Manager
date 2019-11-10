//
// Created by cherit on 11/2/19.
//

#ifndef PROJECT01_UI_H
#define PROJECT01_UI_H


#include "structures/Leaf.h"
/**
 *  Implementation of user's interface
 *
 *  Uses graph to manage it's data.
 */
class UI {
private:
    Vertex* rootVertex;
    Vertex* currentVertex;
public:
    /**
     * Creates UI, defining rootVertex and currentVertex with whole graph
     */
    UI();
    /**
     * Change's currentVertex based on command argument
     */
    void cd_cmd();
    /**
     * Creates new object if in leaf, with a name in an argument
     */
    void mo_cmd();
    /**
    * Deletes existing object if in leaf, with a name in an argument
    */
    void do_cmd();
    /**
    * Modifies existing object if in leaf, with a name in an argument
    */
    void mdo_cmd();
    /**
    * Displays project's structure from a current vertex, based on inheritence
    */
    void dir_cmd();
    /**
    * Displays existing object details, with a name in an argument
    */
    void show_cmd();
    /*
     * Saves all objects into a file, given in argument
     */
    void save_cmd();
    /**
     * Read objects from a file, given in argument
     */
    void read_cmd();
    /**
     * Displays project's structure, based on inheritence
     */
    void tree_cmd();
    /**
     * Displays help
     */
    void help_cmd();
    /**
     * Starts main project loop, allows interaction with an user
     */
    void run();
};


#endif //PROJECT01_UI_H
