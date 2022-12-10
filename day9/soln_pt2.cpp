#include <iostream>
#include <vector>
#include <set>

using namespace std;

//enum dir_t { L, R, U, D }

struct pos_t {
    int x;
    int y;
};

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

class Rope {
    private:
        vector<pos_t> rope;
        set<pair<int,int>> tail_visited;
    public:
        Rope(int n) {
            rope = vector<pos_t>(n);
            tail_visited.insert({rope.back().x, rope.back().y});
        }
        void move(char dir) {
            auto &head = rope.front();
            auto &tail = rope.back();
            switch (dir) {
                case 'U':
                    head.y += 1;
                    break;
                case 'D':
                    head.y -= 1;
                    break;
                case 'L':
                    head.x -= 1;
                    break;
                case 'R':
                    head.x += 1;
                    break;
            }
            for (int i = 1; i < rope.size(); i++) {
                auto &prev = rope[i-1];
                auto &curr = rope[i];

                int dx = prev.x - curr.x;
                int dy = prev.y - curr.y;
                int dist = max(abs(dx), abs(dy));
                if (dist >= 2) {
                    curr.x += sgn(dx);
                    curr.y += sgn(dy);
                }
            }
            tail_visited.insert({tail.x, tail.y});
        }
        int num_visited() {
            return tail_visited.size();
        }
};

int main() {
    char c;
    int n;
    Rope rope(10);
    while (cin >> c >> n) {
        for (int i = 0; i < n; i++) {
            rope.move(c);
        }
    }
    cout << rope.num_visited() << "\n";
}

