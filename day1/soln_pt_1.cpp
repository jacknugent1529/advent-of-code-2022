
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int most_elf_has = 0;

    int n = 0;
    while (cin) {
        int curr = 0;
        string str;
        while (getline(cin, str) && str.length() > 0) {
            curr += stoi(str);
        }

        most_elf_has = max(most_elf_has, curr);
    };
    cout << most_elf_has << '\n';
}