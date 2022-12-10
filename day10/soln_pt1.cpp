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

int main() {
    int reg = 1;
    int cycles = 1;

    string line;
    int sum_strength = 0;

    while (getline(cin, line) && line.length() > 0) {
        ParseState s {0, line};
        string cmd = get_word(s);

        if (cmd == "addx") {
            // cycle 1

            if ((cycles - 20) % 40 == 0) {
                sum_strength += cycles * reg;
            }
            
            cycles += 1;

            // cycle 2
            if ((cycles - 20) % 40 == 0) {
                sum_strength += cycles * reg;
            }
            
            cycles += 1;
            reg += stoi(get_word(s));
        } else {
            // noop
            if ((cycles - 20) % 40 == 0) {
                sum_strength += cycles * reg;
            }

            cycles += 1;
        }
    }

    cout << sum_strength << "\n";
}
