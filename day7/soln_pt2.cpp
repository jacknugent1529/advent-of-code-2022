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
    int used = 0;

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
            used += size;
            string path("");
            for (auto dir : cwd) {
                path.append(dir);
                // don't need to check since will have gotten to cd first
                folder_sizes.at(path) += size;
            }
        }
    }

    // print results
    int best = INT_MAX;
    int disk_size = 70000000;
    for (auto k : folder_sizes) {
        int size = k.second;
        int unused = disk_size - used + size;
        if (size < best && unused > 30000000) {
            best = size;
        }
        

    }
    cout << best << "\n";
    
}
