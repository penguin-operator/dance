#include "tab.hpp"

TAB::TAB(int height, int width, int y, int x) {
    this->height = height;
    this->width = width;
    this->y = y;
    this->x = x;
    this->win = newwin(height, width, y, x);
    box(this->win, 0, 0);
    wrefresh(this->win);
}

void TAB::refresh () {
    char c = getch();
    for (auto& [k, v] : keybindings) {
        if (c == k) {
            v();
        }
    }
}
