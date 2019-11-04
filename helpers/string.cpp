//
// Created by cherit on 11/2/19.
//
#include <string>
#include <vector>

using namespace std;
vector<string> split_str(string text, char separator)
{
    vector<string> array;
    int beg = 0;
    for (int i = 0; i < text.length(); ++i) {
        if(text[i] == separator)
        {
            array.push_back(text.substr(beg, i-beg));
        }
    }
    return array;
}

string

