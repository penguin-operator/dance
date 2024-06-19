#include <ncurses.h>
#include <map>
#include <functional>

#ifndef _TAB_HPP_
#define _TAB_HPP_

using namespace std;

class TAB {
protected:
    WINDOW* win;
    bool focus = false;
    int height, width, y, x;
    map<char, function<void()>> events {
        {'q', [this]() {
            mvwaddch(this->win, 1, 1, 'q');
        }},
        {'e', [this]() {
            mvwaddch(this->win, 1, 1, 'e');
        }},
    };
public:
    TAB(int, int, int, int);
    void refresh();
};

#endif