//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_ARTICLE_H
#define PROJECT01_ARTICLE_H


#include <vector>
#include "Daily.h"
#include "Weekly.h"

class Article: public Daily, public Weekly {
private:
    string author_first_name;
    string author_last_name;
    vector<string> pictures;
    string content;
protected:
    string subject;
public:
    Article();
    Article(ifstream&);

    string getAuthorFirstName();
    string getAuthorLastName();
    string getAuthorName();
    string getSubject();
    string getContent();
    vector<string> getPictures();
    void putDetails(ofstream&);
    void printDetails();
    void printShortDescription();
    void printPictures();
    void setAuthorFullName(string, string);
    void setSubject(string);
    void setContent(string);
    void addPicture(string);
    void update();
    friend std::ostream& operator<<(std::ostream& output, const Article& article);

};


#endif //PROJECT01_ARTICLE_H
