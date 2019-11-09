//
// Created by cherit on 11/3/19.
//

#include <iostream>
#include <fstream>
#include <limits>
#include "Article.h"

Article::Article(): Weekly(), Daily() {
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string tmp;
    int pictures;
    cout << "\t\tARTICLE" << endl;

    cout << "Subject:" << endl;
    getline(cin, this->subject);
    cout << "Author's first name:" << endl;
    getline(cin, this->author_first_name);
    cout << "Author's last name:" << endl;
    getline(cin, this->author_last_name);
    cout << "Content:" << endl;
    getline(cin, this->content);

    cout << "Number of pictures:" << endl;
    cin >> pictures;
    cout << "Your pictures: " << endl;
    for (int i = 0; i < pictures; i++) {
        getline(cin, tmp);
        this->addPicture(tmp);
    }

}
Article::Article(ifstream& InputFile): Weekly(InputFile), Daily(InputFile) {
    int tmp;
    string tmp_picture;
    getline(InputFile, this->author_first_name);
    getline(InputFile, this->author_last_name);
    cin >> tmp;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    for (int i = 0; i < tmp; i++) {
        getline(InputFile, tmp_picture);
        this->pictures.push_back(tmp_picture);
    }
    getline(InputFile, this->content);
    getline(InputFile, this->subject);


}

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
    Weekly::putDetails(OutputFile);
    Daily::putDetails(OutputFile);
    OutputFile << this->author_first_name << endl;
    OutputFile << this->author_last_name << endl;
    OutputFile << this->pictures.size() << endl;
    for (int i = 0; i < this->pictures.size(); ++i) {
        OutputFile << this->pictures[i] << endl;
    }
    OutputFile << this->content << endl;
    OutputFile << this->subject << endl;
}
void Article::printDetails() {
    Weekly::printDetails();
    Daily::printDetails();
    cout << "ARTICLE: " << endl;
    cout << "\tAuthor: " << this->getAuthorName() << endl;
    cout << "\tSubject: " << this->subject << endl;
    cout << "\tContent: " << this->content << endl;
    cout << "\tPictures: " << endl;
    this->printPictures();
}

void Article::printShortDescription() {
    cout << this->name << endl;
    cout << "\t\"" << this->subject <<"\" by " << this->getAuthorName() << " published by " << this->publisher_name << endl;
    cout << "\t Published at: " << this->publishment_area << " in " << this->title << " " << this->magazine_number << endl;
}

std::ostream& operator<<(std::ostream &output, const Article& article) {
    output << article.name << endl;
    return output;
}
void Article::update() {
    Weekly::update();
    Daily::update();
    Object_interface::updateStr("Subject", this->subject);
    Object_interface::updateStr("Author's first name", this->author_first_name);
    Object_interface::updateStr("Author's last name", this->author_last_name);
    Object_interface::updateStr("Content", this->content);
    for (int i = 1; i <= this->pictures.size(); i++) {
        Object_interface::updateStr("Picture nr. " + i, this->pictures[i-1]);
    }
}
