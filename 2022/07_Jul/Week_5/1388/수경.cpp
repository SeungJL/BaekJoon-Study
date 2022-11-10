#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[50][50];  // -: 0 |: 1

int countWidth() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 1) {
                if (cnt > 0) {
                    ans++;
                    cnt = 0;
                }
            } else cnt++;
        }
        if (cnt > 0) ans++;
    }
    return ans;
}

int countHeight() {
    int ans = 0;
    for (int i = 0; i < M; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (arr[j][i] == 0) {
                if (cnt > 0) {
                    ans++;
                    cnt = 0;
                }
            } else cnt++;
        }
        if (cnt > 0) ans++;
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            if (tmp[j] == '-') arr[i][j] = 0;
            else if (tmp[j] == '|') arr[i][j] = 1;
        }
    }

    cout << countWidth() + countHeight() << endl;


    return 0;
}