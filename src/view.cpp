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
        VIEW(int32_t y, int32_t x, int32_t h, int32_t w) {
            this->y = y;
            this->x = x;
            this->h = h;
            this->w = w;
            win = newwin(h, w, y, x);
            wrefresh(win);
            current = 0;
        }
        VIEW(int32_t y, int32_t x, int32_t h, int32_t w, vector<TAB> tabs) {
            VIEW(y, x, h, w);
            this->tabs = tabs;
            for (int i = 0; i < tabs.size(); i++) {
                tabs[i].newwin(win);
            }
        }
        VIEW(int32_t y, int32_t x, int32_t h, int32_t w, TAB tab) {
            VIEW(y, x, h, w);
            this->tabs.push_back(tab);
            tabs[0].newwin(win);
        }
        void refresh() {
            if (current <= tabs.size()) current = tabs.size();
            for (int i = 0; i < tabs.size(); i++) {
                if (i == current) {
                    tabs[i].refresh(win);
                }
            }
            wrefresh(win);
        }
};
