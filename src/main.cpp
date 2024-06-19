#include <ncurses.h>
#include "tab.hpp"
#include "editor.hpp"
using namespace std;

static int height, width;

int main(int argc, char** argv) {
    initscr();
    noecho();
    start_color();
    getmaxyx(stdscr, height, width);

    EDITOR e(height, width / 2, 0, 0, "test.txt");
    TAB t(height / 2, width / 2, 0, width / 2);

    while (1) {
        refresh();
        e.refresh();
        t.refresh();
    }

    endwin();
    return 0;
}
