#include <bits/stdc++.h>

using namespace std;

int N;
bool visited[8];
int num[8];

void DFS(int cnt) {
    if (cnt == N) {
        for (int i = 0; i < N; i++) {
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i] == true) continue;
        visited[i] = true;
        num[cnt] = i + 1;
        DFS(cnt + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> N;
    DFS(0);
    return 0;
}