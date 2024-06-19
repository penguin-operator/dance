#include <ncurses.h>
#include "editor.hpp"

EDITOR::EDITOR(int height, int width, int y, int x) : TAB(height, width, y, x) {
    this->filename = "";
    mvwaddstr(this->win, 0, 1, "newfile*");
}

EDITOR::EDITOR(int height, int width, int y, int x, string filename) : TAB(height, width, y, x) {
    this->filename = filename;
    mvwaddstr(this->win, 0, 1, filename.c_str());
}

void EDITOR::refresh() {
    TAB::refresh();
}
