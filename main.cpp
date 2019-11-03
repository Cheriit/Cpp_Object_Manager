#include <iostream>
#include <vector>
#include "helpers/string.cpp"
#include "src/UI.h"
#include "src/structures/Vertex.h"
#include "src/structures/Leaf.h"

Vertex* generateTree()
{
    Vertex* root = new Vertex();
    return root;
}
UI* setup(){
    UI* ui = new UI(root);
    return ui;
};
using namespace std;
int main() {
    UI* ui = setup();
    vector<string> command;
    string line;
    while(true)
    {
        cin>>line;
        command = split_str(line, ' ');
        if( command[0] == "CD" || command[0] == "cd")           ui->cd_cmd(command[1]);
        else if( command[0] == "MO" || command[0] == "mo" )     ui->mo_cmd(command[1]);
        else if( command[0] == "DO" || command[0] == "do" )     ui->do_cmd(command[1]);
        else if( command[0] == "MDO" || command[0] == "mdo" )   ui->mdo_cmd(command[1]);
        else if( command[0] == "DIR" || command[0] == "dir" )   ui->dir_cmd();
        else if( command[0] == "SHOW" || command[0] == "show" ) ui->show_cmd();
        else if( command[0] == "SAVE" || command[0] == "save" ) ui->save_cmd(command[1]);
        else if( command[0] == "READ" || command[0] == "read" ) ui->read_cmd(command[1]);
        else if( command[0] == "TREE" || command[0] == "tree" ) ui->tree_cmd();
        else if( command[0] == "HELP" || command[0] == "help" ) ui->help_cmd();
        else if( command[0] == "EXIT" || command[0] == "exit" ) break;
    }
    return 0;
}