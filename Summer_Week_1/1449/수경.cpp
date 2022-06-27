#include <bits/stdc++.h>

using namespace std;

int N, L;
vector<int> tape;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        tape.push_back(tmp);
    }
    sort(tape.begin(), tape.end());

    int cnt = 0;
    int pivot = 0;
    for (int i = 0; i < N; i++) {
        if (tape[i] - tape[pivot] + 1 > L) {
            cnt++;
            pivot = i;
        }
    }
    cout << cnt + 1;

    return 0;
}