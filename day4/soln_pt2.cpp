#include <iostream>
#include <vector>

using namespace std;

int main() {

    int tot = 0;

    int l1, r1, l2, r2;
    char c;
    while (cin >> l1 >> c >> r1 >> c >> l2 >> c >> r2) {
        if (l1 > l2) {
            if (l1 <= r2) {
                tot++;
            }
        } else {
            if (l2 <= r1) {
                tot++;
            }
        }
    }

    cout << "part 2: " << tot << "\n";
}
