#include <ncurses.h>
#include <string>
using std::string;

class TAB {
    private:
        string name;
    public:
        TAB(string name, WINDOW* win) {
            this->name = name;
        }
        string name() {
            return name;
        }
        string name(string name) {
            this->name = name;
            return name;
        }
        void refresh(WINDOW* win) {
            wrefresh(win);
        }
        bool delwin(WINDOW* win) {
            return 1;
        }
};
