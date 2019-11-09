//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include "Article.h"

Article::Article(): Weekly(), Daily() {}
Article::Article(ifstream& InputFile): Weekly(InputFile), Daily(InputFile) {}

string Article::getAuthorFirstName() { return this->author_first_name; }
string Article::getAuthorLastName() { return this->author_last_name; }
string Article::getAuthorName() { return this->author_first_name + " " + this->author_last_name; }
string Article::getSubject() { return this->subject; }
string Article::getContent() { return  this->content; }
vector<string> Article::getPictures() { return this->pictures; }

void Article::setAuthorFullName(string first_name, string last_name) {
    this->author_first_name = first_name;
    this->author_last_name = last_name;
}
void Article::setSubject(string subject) { this->subject = subject; }
void Article::setContent(string content) { this->content = content; }
void Article::addPicture(string picture) { this->pictures.push_back(picture); }

void Article::printPictures() {
    for (const auto & picture : this->pictures) {
        cout << "\t\t" << picture << endl;
    }
}
void Article::putDetails(ofstream& OutputFile){
    OutputFile << "ARTICLE" << endl;
    OutputFile << this->name << endl;
    OutputFile << this->author_first_name << endl;
    OutputFile << this->author_first_name << endl;
    OutputFile << this->pictures.size() << endl;
    for (int i = 0; i < this->pictures.size(); ++i) {
        OutputFile << this->pictures[i] << endl;
    }
    OutputFile << this->content << endl;
    OutputFile << this->subject << endl;
    Weekly::putDetails(OutputFile);
    Daily::putDetails(OutputFile);
}
void Article::printDetails() {
    cout << this->name << endl;
    cout << "ARTICLE: " << endl;
    cout << "\tAuthor: " << this->getAuthorName() << endl;
    cout << "\tSubject: " << this->subject << endl;
    cout << "\tContent: " << this->content << endl;
    cout << "\tPictures: " << endl;
    this->printPictures();
    Weekly::printDetails();
    Daily::printDetails();
}

void Article::printShortDescription() {
    cout << this->name << endl;
    cout << "\t\"" << this->subject <<"\" by " << this->getAuthorName() << " published by " << this->publisher_name << endl;
    cout << "\t Published at: " << this->publishment_area << " in " << this->title << " " << this->magazine_number << endl;
}

std::ostream& operator<<(std::ostream &output, const Article& article) {
    output << article.name << endl;
    output << "\t\"" << article.subject <<"\" by " << article.author_first_name << " " << article.author_last_name << " published by " << article.publisher_name << endl;
    output << "\t Published at: " << article.publishment_area << " in " << article.title << " " << article.magazine_number << endl;
    return output;
}
void Article::update() {
    Weekly::update();
    Daily::update();
}
