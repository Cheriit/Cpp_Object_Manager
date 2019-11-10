//
// Created by cherit on 11/3/19.
//

#ifndef PROJECT01_ARTICLE_H
#define PROJECT01_ARTICLE_H


#include <vector>
#include "Daily.h"
#include "Weekly.h"

/**
 * Article class
 */
class Article: public Daily, public Weekly {
private:
    string author_first_name;
    string author_last_name;
    vector<string> pictures;
    string content;
protected:
    string subject;
public:
    /**
     * Creates new instance of article interacting with an user
     */
    Article();
    /**
     * Creates new instance of article based on file's content
     * @param ifstream& file stream
     */
    explicit Article(ifstream&);
    /**
     * Return Author's first name
     * @return string
     */
    string getAuthorFirstName();
    /**
     * Return Author's last name
     * @return string
     */
    string getAuthorLastName();
    /*
     * Return Author's name
     * @return string
     */
    string getAuthorName();
    /**
     * Return article's subject
     * @return
     */
    string getSubject();
    /**
     * Return article's content
     * @return string
     */
    string getContent();
    /**
     * Return article's pictures urls
     * @return vector<string>
     */
    vector<string> getPictures();
    /**
     * Save object data into a file
     * @param ofstream& files stream
     */
    void putDetails(ofstream&) override;
    /**
     * Prints object's data
     */
    void printDetails() override;
    /**
     * Prints object's short version of data
     */
    void printShortDescription();
    /**
     * Print all pictures url
     */
    void printPictures();
    /**
     * Set author's data
     * @param string first_name
     * @param string last_name
     */
    void setAuthorFullName(string, string);
    /**
     * Set article's subject
     * @param string subject
     */
    void setSubject(string);
    /**
     * Set article's content
     * @param content
     */
    void setContent(string);
    /**
     * Add new picture to the article
     * @param string picture
     */
    void addPicture(string);
    /**
     * Updates objects content interacting with the user
     */
    void update() override;
    /**
     * Destroys object instance
     */
    ~Article();
};
#endif //PROJECT01_ARTICLE_H
