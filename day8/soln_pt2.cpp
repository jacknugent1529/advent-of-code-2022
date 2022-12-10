#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int count_visible_dir(
        vector<vector<int>> &forest, 
        int i, int j, int di, int dj
){

    int curr = forest[i][j];
    int tot = 0;
    i += di;
    j += dj;
    while (0 <= i && i < forest.size() && 0 <= j && j < forest[0].size()) {
        tot += 1;
        if (forest[i][j] >= curr) {
            break;
        }

        i += di;
        j += dj;
    }

    return tot;
}

int get_scenic_score(vector<vector<int>> &forest, int i, int j){
    int right = count_visible_dir(forest, i, j, 0, 1);
    int left = count_visible_dir(forest, i, j, 0, -1);
    int up = count_visible_dir(forest, i, j, -1, 0);
    int down = count_visible_dir(forest, i, j, 1, 0);
    int score = right * left * up * down;
    return score;
}

int get_max_scenic_score(vector<vector<int>> &forest){

    int I = forest.size();
    int J = forest[0].size();

    int max_score = 0;
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            max_score = max(max_score, get_scenic_score(forest, i, j));
        }
    }

    return max_score;
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
    //cout << get_scenic_score(forest, 1, 2) << "\n";

    cout << get_max_scenic_score(forest) << "\n";
}
