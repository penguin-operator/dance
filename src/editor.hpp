#include <string>
#include <vector>
#include "tab.cpp"

using namespace std;

class EDITOR : TAB {
    int topline;
    int maxlines;
    int curs_y, curs_x;
    vector<string> lines;
    string filename;
    map<char, void(*)()> events {
        {'\t', []() {}},
    };
public:
    EDITOR(int height, int width, int y, int x);
    EDITOR(int height, int width, int y, int x, string filename);
};
