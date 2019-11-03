//
// Created by cherit on 11/2/19.
//

#ifndef PROJECT01_UI_H
#define PROJECT01_UI_H


#include "structures/Vertex.h"

class UI {
private:
    Vertex* rootVertex;
    Vertex* currentVertex;
public:
    void cd_cmd(string);
    void mo_cmd(string);
    void do_cmd(string);
    void mdo_cmd(string);
    void dir_cmd();
    void show_cmd(string);
    void save_cmd(string);
    void read_cmd(string);
    void tree_cmd();
    void help_cmd();
    void run();
};


#endif //PROJECT01_UI_H
