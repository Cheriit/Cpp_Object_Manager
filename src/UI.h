//
// Created by cherit on 11/2/19.
//

#ifndef PROJECT01_UI_H
#define PROJECT01_UI_H


#include "structures/Leaf.h"

class UI {
private:
    Vertex* rootVertex;
    Vertex* currentVertex;
public:
    UI();
    void cd_cmd();
    void mo_cmd();
    void do_cmd();
    void mdo_cmd();
    void dir_cmd();
    void show_cmd();
    void save_cmd();
    void read_cmd();
    void tree_cmd();
    void help_cmd();
    void run();
};


#endif //PROJECT01_UI_H
