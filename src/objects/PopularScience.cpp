//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include "PopularScience.h"

PopularScience::PopularScience(): Book() {}
PopularScience::PopularScience(ifstream& InputFile): Book(InputFile) {}

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
    OutputFile << "POPULARSCIENCE" << endl;
    OutputFile << this->name << endl;
    OutputFile << this->field_of_study << endl;
    OutputFile << this->sources.size() << endl;
    for (int i = 0; i < this->sources.size(); ++i) {
        OutputFile << this->sources[i] << endl;
    }

    Book::putDetails(OutputFile);
}
void PopularScience::printDetails() {
    cout << this->name << endl;
    cout << "POPULARSCIENCE: " << endl;
    cout << "\tField of study: " << this->field_of_study << endl;
    cout << "\tSources:" << endl;
    this->printSources();
    Book::printDetails();
}

void PopularScience::printShortDescription() {
    cout << this->name << endl;
    cout << "\t\"" << this->title <<"\" by " << this->author << " published by " << this->publisher_name << endl;
    cout << "\t Field of study: " << this->field_of_study << endl;
}

std::ostream& operator<<(std::ostream& output, const PopularScience& bestseller) {
    output << bestseller.name << endl;
    output << "\t\"" << bestseller.title <<"\" by " << bestseller.author << " published by " << bestseller.publisher_name << endl;
    output << "\t Field of study: " << bestseller.field_of_study << endl;
    return  output;
}
void PopularScience::update() {
    Book::update();
}