#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector <string> tmp; // 만든 단어 전부 담아둘거임
    string input, v;
    string w1, w2, w3;

    cin >> input;
    int n = input.size();

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {

            w1 = input.substr(0, i + 1); // 0 ~ i
            w2 = input.substr(i + 1, j - i); // i+1 ~ j
            w3 = input.substr(j + 1); // j+1 ~ n

            reverse(w1.begin(), w1.end());
            reverse(w2.begin(), w2.end());
            reverse(w3.begin(), w3.end());

            v = w1 + w2 + w3;
            tmp.push_back(v);

        }
    }

    sort(tmp.begin(), tmp.end());
    cout << tmp[0] << endl;



    return 0;
}