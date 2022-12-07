#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

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
    string str;

    vector<string> cwd;

    unordered_map<string, int> folder_sizes;

    while (getline(cin, str) && str.length() > 0) {
        ParseState state = {0, str};
        string fw = get_word(state); // first word

        bool isdigit = 0 <= fw[0] - '0' && fw[0] - '0' < 10;
        if (!isdigit) {
            // ls or cd
            string sw = get_word(state);

            if (sw == "cd") {
                string dir = get_word(state);
                if (dir == "..") {
                    cwd.pop_back();
                } else {
                    cwd.push_back(dir);

                    string path = accumulate(cwd.begin(), cwd.end(), string(""));
                    folder_sizes[path] = 0;
                }
            }
        } else {
            int size = stoi(fw);
            string path("");
            for (auto dir : cwd) {
                path.append(dir);
                // don't need to check since will have gotten to cd first
                folder_sizes.at(path) += size;
            }
        }
    }

    // print results
    int tot = 0;
    for (auto k : folder_sizes) {
        int size = k.second;
        if (size <= 100000) {
            tot += size;
        }
    }
    cout << tot << "\n";
    
}
