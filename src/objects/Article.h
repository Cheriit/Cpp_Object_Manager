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
    string cintent;
protected:
    string topic;
public:
    string getAuthorFirstName();
    string getAuthorLastName();
    string getAuthorName();
    string getTopic();
    vector<string> getPictures();
    string getDetails();
    void printDetails();
    void printShortDescription();
    void setAuthorFullName(string);
    void setTopic(string);
    void setContent(string);
    void addPhoto(string);
    bool removePhoto(string);
    void update();
    friend std::ostream& operator<<(std::ostream& output, const Article& article);

};


#endif //PROJECT01_ARTICLE_H
