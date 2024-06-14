#include <ncurses.h>
#include <map>

class TAB {
    WINDOW* win;
    int height, width, y, x;
    map<char, void(*)()> events;
public:
    TAB(int height, int width, int y, int x);
    void refresh();
};
