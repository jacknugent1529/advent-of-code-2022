#include <iostream>
#include <vector>

using namespace std;

int score(int l, int r) {
    int shape = r + 1;
    int outcome = 0;
    if (r == l) {
        outcome = 3;
    } else if (r == (l + 1) % 3) {
        outcome = 6;
    }
    return shape + outcome;
}

int main() {
    char l;
    char r;
    int tot = 0;
    while (cin >> l) {
        cin >> r;
        //cout << "l: " << l << " r: " << r << "\n";
        l -= 'A';
        r -= 'X';
        tot += score(l,r);
    }
    cout << tot << "\n";
}
