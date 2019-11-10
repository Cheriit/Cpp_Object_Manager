//
// Created by cherit on 11/10/19.
//

#ifndef PROJECT01_READER_H
#define PROJECT01_READER_H


#include <fstream>
/**
 *  Class with utils helping reading from source
 *
 *  All of it's methods are static
 */
class Reader {
public:
    /**
     * Static function returning read and processed number from source
     * @param ifstream& Input file stream
     * @return float Processed number
     */
    static float readNum(std::ifstream&);
    /**
     * Static function reading and processing number from cin to a given type, displaying given text
     * @param string displaying text
     * @param  T&    pointer to save
     * @tparam T type
     */
    template <class T>
    static void readNum(std::string, T&);
    /**
     * Static function reading and processing number from cin to a string pointer, displaying given text
     * @param string displaying text
     * @param  string&    pointer to save
     */
    static void readString(std::string, std::string&);
};

template<class T>
void Reader::readNum(std::string text, T& target) {
    std::string tmp;
    bool try_again = true;
    T tmp_float;
    std::cout << text << ":" << std::endl;
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


#endif //PROJECT01_READER_H
