//
// Created by cherit on 11/2/19.
//
#include <iostream>
#include <fstream>
#include "../helpers/string.cpp"

#include "UI.h"
#include "objects/Article.h"
#include "objects/Bestseller.h"
#include "objects/Monthly.h"
#include "objects/PopularScience.h"

UI::UI() {
    this->rootVertex = Vertex::generateStructureTree();
    this->currentVertex = this->rootVertex;
}
void UI::cd_cmd() {
    string name;
    cin>>name;
    Vertex* found_vertex = this->rootVertex->findVertex(name);
    if (found_vertex != nullptr )
    {
        this->currentVertex = found_vertex;
        cout << "Changed current vertex to " << found_vertex->getClassName() << endl;
    }
    else cout << "Vertex doesn't exist" << endl;
}

void UI::mo_cmd() {
    string name;
    cin>>name;
    if ( this->currentVertex->isLeaf() )
    {
        if( !Object_interface::nameExists(name) )
        {
            Publisher* obj;
            if ( this->currentVertex->getClassName() == "Article" )
                obj = new Article();
            else if ( this->currentVertex->getClassName() == "Bestseller" )
                obj = new Bestseller();
            else if ( this->currentVertex->getClassName() == "Monthly" )
                obj = new Monthly();
            else if ( this->currentVertex->getClassName() == "PopularScience" )
                obj = new PopularScience();
            obj->setName(name);
            Leaf* leaf =dynamic_cast<Leaf*>(this->currentVertex);
            leaf->addElement(obj);
            cout<<"New object with name \"" << name << "\" has been created." << endl;
        }
        else
            cout << "Object with a name \"" << name << "\" already exists." << endl;
    }
    else
        cout << "It's not a leaf." << endl;
}

void UI::do_cmd() {
    string name;
    cin>>name;
    if ( this->currentVertex->isLeaf() )
    {
        Leaf* leaf =dynamic_cast<Leaf*>(this->currentVertex);
        leaf->removeElement(name);
    }
    else
        cout << "It's not a leaf." << endl;
}

void UI::mdo_cmd() {
    string name;
    cin>>name;
    if ( this->currentVertex->isLeaf() )
    {
        Publisher* obj = this->currentVertex->findObject(name);
        if ( obj != nullptr ) obj->update();
        else cout << "There's no object with name " << name << endl;
    }
    else
        cout << "It's not a leaf." << endl;
}

void UI::dir_cmd() {
    this->currentVertex->printObjects();
}

void UI::show_cmd() {
    string name;
    cin>>name;
    Publisher* object = this->rootVertex->findObject(name);
    if (object == nullptr)  cout << "Object with given name doesn't exists" << endl;
    else                    object->printDetails();
}

void UI::save_cmd() {
    string file_name;
    cin>>file_name;
    ofstream OutputFile;
    OutputFile.open(file_name, fstream::out);
    if (!OutputFile.is_open())
        cout << "Unable to create file " << file_name;
    else
    {
        int count = 0;
        string leafes[4] = { "Bestseller", "PopularScience", "Monthly", "Article"};
        for (int i = 0; i < 4; i++) {
            Leaf* searchingLeaf = dynamic_cast<Leaf *>(this->rootVertex->findVertex(leafes[i]));
            map<string, Publisher*> elements = searchingLeaf->getElements();
            map<string, Publisher*>::iterator it;
            for ( it = elements.begin(); it != elements.end(); it++ )
            {
                OutputFile << leafes[i] << endl;
                OutputFile << it->first << endl;
                it->second->putDetails(OutputFile);
                count++;
            }
        }
        cout << "Succesfully exported " << count << " objects." << endl;
        OutputFile.close();
    }
}

void UI::read_cmd() {
    string file_name;
    cin>>file_name;
    ifstream InputFile;
    InputFile.open(file_name, fstream::in);
    if (!InputFile.is_open())
        cout << "Unable to create file " << file_name;
    else
    {
        int count=0;
        while (!InputFile.eof())
        {
            Publisher* obj;
            string class_name, obj_name;
            getline(InputFile, class_name);
            getline(InputFile, obj_name);
            if (obj_name == "" || class_name == "") break;
            if (Object_interface::nameExists(obj_name))
            {
                cout << "Names conflict! - " << obj_name << endl;
                break;
            }
            cout << "Found " << obj_name << " - an instance of " << class_name << endl;
            if ( class_name == "Article" )
                obj = new Article(InputFile);
            else if ( class_name == "Bestseller" )
                obj = new Bestseller(InputFile);
            else if ( class_name == "Monthly" )
                obj = new Monthly(InputFile);
            else if ( class_name == "PopularScience" )
                obj = new PopularScience(InputFile);
            obj->setName(obj_name);
            Leaf* searchingLeaf = dynamic_cast<Leaf *>(this->rootVertex->findVertex(class_name));
            searchingLeaf->addElement(obj);
            count++;
        }
        InputFile.close();
        cout << "Succesfully imported " << count << " objects." << endl;
    }

}

void UI::tree_cmd() {
    this->rootVertex->printStructure(0);
}

void UI::help_cmd() {
    cout << "Available commands: " << endl;
    cout << "\t CD [vertex]      \t changes active vertex to defined vertex(starting vertex is \"Publisher\")" << endl;
    cout << "\t MO [name]        \t creates new instance of the current leaf with defined name" << endl;
    cout << "\t DO [name]        \t removes instance of the current leaf with defined name" << endl;
    cout << "\t MDO [name]       \t modifies instance of the current leaf with defined name" << endl;
    cout << "\t DIR              \t displays objects names based on current vertex." << endl;
    cout << "\t SHOW [name]      \t displays detailed data of given object, based on name parameter." << endl;
    cout << "\t SAVE [file_name] \t saves all data to a given file (files are saved in main catalogue)." << endl;
    cout << "\t READ [file_name] \t read all data from a given file (files are saved in main catalogue) into this app." << endl;
    cout << "\t TREE             \t displays app's structure." << endl;
    cout << "\t EXIT             \t shut down's app." << endl;
    cout << "Availavble vertexes: " << endl;
    cout << "\t Publisher" << endl;
    cout << "\t Book" << endl;
    cout << "\t Magazine" << endl;
    cout << "\t Weekly" << endl;
    cout << "\t Daily" << endl;
    cout << "\t PopularScience \t (leaf)" << endl;
    cout << "\t Bestseller     \t (leaf)" << endl;
    cout << "\t Monthly        \t (leaf)" << endl;
    cout << "\t Article        \t (leaf)" << endl;
    cout << "Object's name must be a single word!" << endl;


}

void UI::run() {
    string command;
    cout << "Welcome in my app." << endl;
    cout << "You can display all accessible commands using command \"HELP\""<<endl;

    while(true)
    {
        cout << endl << "(" << this->currentVertex->getClassName() << ") >>> ";
        cin>>command;
        if( command == "CD" || command == "cd")           this->cd_cmd();
        else if( command == "MO" || command == "mo" )     this->mo_cmd();
        else if( command == "DO" || command == "do" )     this->do_cmd();
        else if( command == "MDO" || command == "mdo" )   this->mdo_cmd();
        else if( command == "DIR" || command == "dir" )   this->dir_cmd();
        else if( command == "SHOW" || command == "show" ) this->show_cmd();
        else if( command == "SAVE" || command == "save" ) this->save_cmd();
        else if( command == "READ" || command == "read" ) this->read_cmd();
        else if( command == "TREE" || command == "tree" ) this->tree_cmd();
        else if( command == "HELP" || command == "help" ) this->help_cmd();
        else if( command == "EXIT" || command == "exit" ) break;
        else cout << "Command \"" << command << "\" not found. Try again!" << endl << endl;
        cin.ignore();
    }

}


