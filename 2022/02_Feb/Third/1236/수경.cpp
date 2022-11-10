#include <bits/stdc++.h>

using namespace std;

bool flag[50][50];
int N, M;

bool checkRow(int i) {
    for (int j = 0; j < M; j++) {
        if (flag[i][j] == true) return true;
    }
    return false;
}

bool checkColumn(int j) {
    for (int i = 0; i < N; i++) {
        if (flag[i][j] == true) return true;
    }
    return false;
}

int solve() {
    int cnt_row = 0, cnt_column = 0;
    for (int i = 0; i < N; i++) if (checkRow(i) == false) cnt_row++;
    for (int j = 0; j < M; j++) if (checkColumn(j) == false) cnt_column++;
    return max(cnt_row, cnt_column);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    cin.get();

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            flag[i][j] = false;
        }
    }

    //입력받기
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            if (tmp[j] == 'X') {
                flag[i][j] = true;
            }
        }
    }

    cout << solve() << '\n';

}