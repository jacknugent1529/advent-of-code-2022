#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

void count_visible_dir(
        vector<vector<int>> &forest, 
        set<tuple<int,int>> &visible,
        int i, int j, int di, int dj
){

    int curr = -1;
    int next = 0;
    while (0 <= i && i < forest.size() && 0 <= j && j < forest[0].size()) {
        next = forest[i][j];
        if (next > curr) {
            tuple<int,int> ij = make_tuple(i,j);
            visible.insert(ij);
        }
        curr = max(curr, next);

        i += di;
        j += dj;
    }
}

int count_visible(vector<vector<int>> &forest){

    set<tuple<int,int>> visible;
    int I = forest.size();
    int J = forest[0].size();
    for (int i = 0; i < I; i++) {
        int j = 0;
        count_visible_dir(forest, visible, i, j, 0, 1);

        j = J - 1;
        count_visible_dir(forest, visible, i, j, 0, -1);
    }
    for (int j = 0; j < J; j++) {
        int i = 0;
        count_visible_dir(forest, visible, i, j, 1, 0);

        i = I - 1;
        count_visible_dir(forest, visible, i, j, -1, 0);
    }

    return visible.size();
}



int main() {
    vector<vector<int>> forest;

    string str;
    while (getline(cin, str) && str.length() > 0) {
        vector<int> line;
        for (char c : str) {
            line.push_back(c - '0');
        }
        forest.push_back(line);
    }

    cout << count_visible(forest) << "\n";
}
