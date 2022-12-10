#include <iostream>
#include <vector>

using namespace std;

struct ParseState {
    int i;
    string s;
};

string get_word(ParseState &s) {
    // mutates state
    int word_i = (s.s).find(' ', s.i);

    string word = (s.s).substr(s.i, word_i - s.i);

    s.i = word_i + 1;
    return word;
}


void cycle(int reg, int &cycles) {
    if (cycles >= 40) {
        cout << "\n";
        cycles -= 40;
    }
    if (abs(reg - cycles) <= 1) {
        cout << "#";
    } else {
        cout << ".";
    }
}

int main() {
    int reg = 1;
    int cycles = 0;

    string line;
    while (getline(cin, line) && line.length() > 0) {
        ParseState s {0, line};
        string cmd = get_word(s);

        if (cmd == "addx") {
            // cycle 1

            cycle(reg, cycles);
            cycles += 1;

            // cycle 2
            cycle(reg, cycles);
            cycles += 1;
            reg += stoi(get_word(s));
        } else {
            // noop
            cycle(reg, cycles);
            cycles += 1;
        }
    }

}
