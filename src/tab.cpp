#include "tab.hpp"

TAB::TAB(int height, int width, int y, int x) {
    this->height = height;
    this->width = width;
    this->y = y;
    this->x = x;
    this->win = newwin(height, width, y, x);
    wrefresh(this->win);
    nodelay(this->win, 1);
    box(this->win, 0, 0);
}

void TAB::refresh () {
    if (this->focus) {
        char c = getch();
        for (auto& [k, v] : this->events) {
            if (c == k) {
                v();
            }
        }
    }
    wrefresh(this->win);
}
