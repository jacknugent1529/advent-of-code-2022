#include <iostream>

using namespace std;


int main() {
    char bufr[13];

    for (int i=0; i<13; i++) {
        cin >> bufr[i];
    }

    int counter = 13;
    char c;
    while (cin >> c) {
        bool unique = true;
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 13; j++) {
                if (i == j) continue;
                if (bufr[i] == bufr[j]) {
                    unique = false;
                }
            }
            if (bufr[i] == c) {
                unique = false;
            }
        }

        if (unique) {
            cout << counter + 1 << "\n";
            return 0;
        } else {
            bufr[counter % 13] = c;
        }

        counter += 1;
    }

}
