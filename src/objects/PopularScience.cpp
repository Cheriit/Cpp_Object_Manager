//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include <limits>
#include "PopularScience.h"
#include "../../helpers/Updater.h"
#include "../../helpers/Reader.h"

PopularScience::PopularScience(): Book() {
    string tmp;
    int sources;
    cout << "\t\tPOPULARSCIENCE" << endl;

    Reader::readString("Field of study", this->field_of_study);

    cout << "Number of sources:" << endl;
    cin >> sources;
    cout << "Your sources: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    for (int i = 0; i < sources; i++) {
        getline(cin, tmp);
        this->addSource(tmp);
    }

}
PopularScience::PopularScience(ifstream& InputFile): Book(InputFile) {
    int tmp;
    string tmp_source;
    getline(InputFile, this->field_of_study);
    tmp = Reader::readNum(InputFile);
    for (int i = 0; i < tmp; i++) {
        getline(InputFile, tmp_source);
        this->sources.push_back(tmp_source);
    }
}

vector<string> PopularScience::getSources() { return this->sources; }
string PopularScience::getFieldOfStudy() { return this->field_of_study; }

void PopularScience::setSources(vector<string> sources) { this->sources = sources; }
void PopularScience::setFieldOfStudy(string field_of_study) { this->field_of_study = field_of_study; }
void PopularScience::printSources() {
    for (int i = 0; i < this->sources.size(); ++i) {
        cout << "\t\t" << this->sources[i] << endl;
    }
}
void PopularScience::addSource(string source) { this->sources.push_back(source); }

void PopularScience::putDetails(ofstream& OutputFile){
    Book::putDetails(OutputFile);
    OutputFile << this->field_of_study << endl;
    OutputFile << this->sources.size() << endl;
    for (int i = 0; i < this->sources.size(); ++i) {
        OutputFile << this->sources[i] << endl;
    }
}
void PopularScience::printDetails() {
    Book::printDetails();
    cout << this->name << endl;
    cout << "POPULARSCIENCE: " << endl;
    cout << "\tField of study: " << this->field_of_study << endl;
    cout << "\tSources:" << endl;
    this->printSources();
}

void PopularScience::printShortDescription() {
    cout << this->name << endl;
    cout << "\t\"" << this->title <<"\" by " << this->author << " published by " << this->publisher_name << endl;
    cout << "\t Field of study: " << this->field_of_study << endl;
}

void PopularScience::update() {
    Book::update();
    Updater::updateStr("Field of study", this->field_of_study);
    for (int i = 1; i <= this->sources.size(); i++) {
        Updater::updateStr("Source nr. " + std::to_string(i), this->sources[i - 1]);
    }
}

PopularScience::~PopularScience() {
    sources.clear();
}
