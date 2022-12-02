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
    char choice;
    int tot = 0;
    while (cin >> l) {
        cin >> r;
        //cout << "l: " << l << " r: " << r << "\n";
        l -= 'A';
        
        switch (r) {
            case 'X':
                choice = (l-1+3) % 3;
                break;
            case 'Y':
                choice = l;
                break;
            case 'Z':
                choice = (l+1) % 3;
                break;
        }

        tot += score(l,choice);
    }
    cout << tot << "\n";
}
