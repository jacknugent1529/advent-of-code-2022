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
        pos_t head;
        pos_t tail;
        set<pair<int,int>> visited;
    public:
        Rope() {
            head = {0,0};
            tail = {0,0};
            visited.insert({tail.x, tail.y});
        }
        void move(char dir) {
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
            int dx = head.x - tail.x;
            int dy = head.y - tail.y;
            int dist = max(abs(dx), abs(dy));
            if (dist >= 2) {
                tail.x += sgn(dx);
                tail.y += sgn(dy);
            }
            visited.insert({tail.x, tail.y});
        }
        int num_visited() {
            return visited.size();
        }
};

int main() {
    char c;
    int n;
    Rope rope;
    while (cin >> c >> n) {
        for (int i = 0; i < n; i++) {
            rope.move(c);
        }
    }

    cout << rope.num_visited() << "\n";

}

