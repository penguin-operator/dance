#include <ncurses.h>
#include "view.cpp"
using namespace std;

int main(int argc, char** argv) {
    initscr();
    nodelay(stdscr, true);
    noecho();
    curs_set(0);

    vector<VIEW> views = {
        VIEW(0, 0, 16, 64),
    };

    while (views.size() > 0) {
        refresh();
        for (int i = 0; i < views.size(); i++) {
            views[i].refresh();
        }
        napms(10);
    }

    endwin();
    return 0;
}
