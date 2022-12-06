#include <iostream>

using namespace std;


int main() {
    char bufr[3];

    cin >> bufr[0] >> bufr[1] >> bufr[2];

    int counter = 3;
    char c;
    while (cin >> c) {
        bool unique = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
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
            //cout << bufr[0] << bufr[1] << bufr[2] << c;
            cout << counter + 1 << "\n";
            return 0;
        } else {
            bufr[counter % 3] = c;
        }

        counter += 1;
    }

}
