#include <ncurses.h>
#include <vector>
#include <string>
#include "tabs/tabs.h"
using std::vector;

class VIEW {
    private:
        WINDOW* win;
        int32_t x, y, w, h;
        vector<TAB> tabs;
    public:
        VIEW() {}
        ~VIEW() {}
};
