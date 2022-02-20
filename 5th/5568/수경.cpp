#include <bits/stdc++.h>

using namespace std;
int n, k;
string card[10];
bool visited[100000000];
bool card_visited[10];
int cnt;

void solve(int len, string num) {
    if (len == k) {
        if (visited[stoi(num)] == false) {
            cnt++;
            visited[stoi(num)] = true;

        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (card_visited[i] == true) {
            continue;
        }
        card_visited[i] = true;
        solve(len + 1, num + card[i]);
        card_visited[i] = false;
    }

}

int main() {
    cnt = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }
    solve(0, "");
    cout << cnt;

    return 0;
}