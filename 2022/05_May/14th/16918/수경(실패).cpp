#include <bits/stdc++.h>

using namespace std;

int bomb[200][200];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int R, C, N;

bool check(int x, int y) {
    for (int i = 0; i < 4; i++) {
        if (x + dx[i] < 0 || x + dx[i] > R - 1 || y + dy[i] < 0 || y + dy[i] > C - 1) continue;
        if (bomb[x + dx[i]][y + dy[i]] == 1) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> N;

    for (int i = 0; i < R; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < tmp.size(); j++) {
            if (tmp[j] == 'O') bomb[i][j] = 1;
        }
    }

    if(N == 1){
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (bomb[i][j] == 1) cout << 'O';
                else cout << '.';
            }
            cout << '\n';
        }
    }
    else if (N % 3 == 1) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << 'O';
            }
            cout << '\n';
        }
    }
    else if (N % 3 == 2) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (bomb[i][j] == 1) cout << 'O';
                else cout << '.';
            }
            cout << '\n';
        }
    }
    else if (N % 3 == 0) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (check(i, j)) cout << '.';
                else cout << 'O';
            }
            cout << '\n';
        }
    }
    return 0;
}