#include <string>
#include <vector>
#include "tab.hpp"

#ifndef _EDITOR_HPP_
#define _EDITOR_HPP_

using namespace std;

class EDITOR : public TAB {
private:
    int topline;
    int maxlines;
    int curs_y, curs_x;
    vector<string> lines;
    string filename;
    map<char, function<void()>> keybinds {
        {'\t', [this]() {}},
    };
public:
    EDITOR(int, int, int, int);
    EDITOR(int, int, int, int, string);
    void refresh();
};

#endif