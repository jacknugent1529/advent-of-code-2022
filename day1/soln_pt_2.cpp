
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> elves;

    make_heap(elves.begin(), elves.end());

    while (cin) {
        int curr = 0;
        string str;
        while (getline(cin, str) && str.length() > 0) {
            curr += stoi(str);
        }

        elves.push_back(curr);
        push_heap(elves.begin(), elves.end());
    };

    int tot = 0;
    for (int i = 0; i < 3; i++) {
        pop_heap(elves.begin(), elves.end());
        tot += elves.back();
        elves.pop_back();
    }

    cout << tot << '\n';
}