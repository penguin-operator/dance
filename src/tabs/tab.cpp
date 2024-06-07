#include <ncurses.h>
#include <string>
using std::string;

class TAB {
    private:
        string title;
    public:
        TAB(string name) {
            this->title = name;
        }
        string name() {
            return title;
        }
        void newwin(WINDOW* win) {
            wrefresh(win);}
        void refresh(WINDOW* win) {
            wrefresh(win);
        }
        bool delwin(WINDOW* win) {
            wrefresh(win);
            return 1;
        }
};
