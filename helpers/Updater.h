//
// Created by cherit on 11/10/19.
//

#ifndef PROJECT01_UPDATER_H
#define PROJECT01_UPDATER_H


#include <string>
#include <iostream>
/**
 *  Class with utils helping updating data
 *
 *  All of it's methods are static
 */
class Updater {
public:
    /**
     * Static function processing and updating string's value
     *
     * @param string  text to display
     * @param string& text pointer to update
     */
    static void updateStr(std::string, std::string&);
    /**
     * Static function processing and updating numerical value
     *
     * @param  string  text to display
     * @param  T&      text pointer to update
     * @tparam T       numeric type to update
     */
    template <class T>
    static void updateNum(std::string, T&);

};
template <class T>
void Updater::updateNum(std::string text, T& target) {
    std::string tmp;
    bool try_again = true;
    float tmp_float;
    std::cout << text << ":(" << target << ")" << std::endl;
    while(try_again)
    {
        try_again = false;
        getline(std::cin, tmp);
        try {
            tmp_float = stof(tmp);
        }catch( const std::invalid_argument& ia) {
            if(!tmp.empty())
            {
                try_again = true;
                std::cout << "Invalid characters. Try again!" << std::endl;
            }
            else tmp_float = target;
        }
    }
    if(!tmp.empty()) target = tmp_float;
}

#endif //PROJECT01_UPDATER_H
