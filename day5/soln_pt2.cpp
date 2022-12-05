#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Pile {
    private:
        vector<stack<char>> pile;
        int n;

    public:
        Pile(vector<string> lines) {
            // last line should list the numbers of pile
            auto l = lines.back();
            int n_ = (l.length() - 3) / 4 + 1;

            vector<stack<char>> pile_(n_);

            for (auto l = lines.end() - 2; l >= lines.begin(); --l) {
                int i = 0;
                int s_i = 1;
                while (s_i < (*l).length()) {
                    char c = (*l)[s_i];
                    if ('A' <= c & c <= 'Z') {
                        pile_[i].push(c); 
                    }

                    s_i += 4;
                    i += 1;
                }
            }
            pile = pile_;
            n = n_;
        }

        int move1(int from, int to) {
            if (pile[from].empty()) {
                return -1;
            }
            char v = pile[from].top();
            pile[from].pop();
            pile[to].push(v);
            return 0;
        }

        int moven(int from, int to, int n) {
            /* this time move all n at the same time */
            if (pile[from].size() < n) {
                return -1;
            }

            vector<char> bfr;
            for (int i=0; i<n; i++) {
                bfr.push_back(pile[from].top());
                pile[from].pop();
            }

            for (auto i = bfr.end(); i-- != bfr.begin(); ) {
                pile[to].push(*i);
            }
            return true;
        }

        string get_stack_tops() {
            string s;
            for (int i = 0; i < pile.size(); i++) {
                if (!pile[i].empty()) {
                    s.push_back(pile[i].top());
                }
            }
            return s;
        }
};

int main() {
    /* parse pile */
    vector<string> pile_lines;
    string str;
    while (getline(cin, str) &&str.length() > 0) {
        cout << "LINE: " << str << "\n";
        pile_lines.push_back(str);
    }

    Pile pile(pile_lines);

    cout << "TOP: " << pile.get_stack_tops() << "\n";

    // process instructions
    int n, from, to;
    string s;
    while (cin >> s >> n >> s >> from >> s >> to) {
        from--;
        to--;
        pile.moven(from, to, n);
    }

    cout << pile.get_stack_tops() << "\n";

}
