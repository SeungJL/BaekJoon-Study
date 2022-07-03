#include <bits/stdc++.h>

using namespace std;


int D(int n) {
    return n * 2 % 10000;
}

int S(int n) {
    if (n == 0) return 9999;
    return n - 1;
}

int L(int n) {
    int tmp = n / 1000;
    n = n * 10 + tmp;
    n = n % 10000;
    return n;
}

int R(int n) {
    int tmp = n % 10;
    n /= 10;
    n = tmp * 1000 + n;
    return n;
}

void BFS(int A, int B) {
    bool visited[10000] = {0};
    queue<pair<int, string>> Q;
    Q.push(make_pair(A, ""));
    visited[A] = true;
    while (!Q.empty()) {
        int cur_num = Q.front().first;
        string cur_str = Q.front().second;
        Q.pop();
        if (cur_num == B) {
            cout << cur_str << "\n";
            return;
        }

        int next_D = D(cur_num);
        if (!visited[next_D]) {
            Q.push(make_pair(next_D, cur_str + "D"));
            visited[next_D] = true;
        }

        int next_S = S(cur_num);
        if (!visited[next_S]) {
            Q.push(make_pair(next_S, cur_str + "S"));
            visited[next_S] = true;
        }

        int next_L = L(cur_num);
        if (!visited[next_L]) {
            Q.push(make_pair(next_L, cur_str + "L"));
            visited[next_L] = true;
        }

        int next_R = R(cur_num);
        if (!visited[next_R]) {
            Q.push(make_pair(next_R, cur_str + "R"));
            visited[next_R] = true;
        }

    }

}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        BFS(A, B);
    }
    return 0;
}