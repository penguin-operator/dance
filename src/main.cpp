#include <ncurses.h>
#include <map>
// #include "tab.hpp"
#include "editor.hpp"
using namespace std;

static int height, width, y = 0, x = 0;

static map<char, void(*)()> keybindings {
    {'q', []() {
        endwin();
        exit(0);
    }},
    {'e', []() {
        curs_set(1);
        attron(COLOR_PAIR(2) | A_BOLD | A_REVERSE);
        mvaddstr(height - 1, 0, "[ EDIT ]");
        attroff(COLOR_PAIR(1) | A_BOLD | A_REVERSE);
        while (1) {
            char c = getch();
            if (c == '\t') break;
            else {
                move(y, x);
                x ++;
                addch(c);
            }
        };
        attron(COLOR_PAIR(1) | A_BOLD | A_REVERSE);
        mvaddstr(height - 1, 0, "[ NORM ]");
        attroff(COLOR_PAIR(1) | A_BOLD | A_REVERSE);
        curs_set(0);
    }},
};

int main(int argc, char** argv) {
    initscr();
    noecho();
    curs_set(0);
    start_color();
    getmaxyx(stdscr, height, width);

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);

    attron(COLOR_PAIR(1) | A_BOLD | A_REVERSE);
    mvaddstr(height - 1, 0, "[ NORM ]");
    attroff(COLOR_PAIR(1) | A_BOLD | A_REVERSE);

    while (1) {
        move(y, x);
    }

    endwin();
    return 0;
}
