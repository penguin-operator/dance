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
        uint8_t current;
    public:
        VIEW() {}
        void refresh() {
            if (current <= tabs.size()) current = tabs.size();
            for (int i = 0; i < tabs.size(); i++)
                if (i == current)
                    tabs[i].refresh(win);
            wrefresh(win);
        }
        ~VIEW() {
            delwin(win);
        }
};
