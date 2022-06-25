#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int n, m, cnt;
    Point(int _n, int _m, int _c) : n(_n), m(_m), cnt(_c) {};
};

int NN[4] = {-1, 0, 1, 0};
int MM[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    // init
    int N, M;
    cin >> N >> M;

    vector< vector<char> > map(N, vector<char>(M, 0));
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) 
            cin >> map[n][m];
    }

    // solve
    queue<Point> Q;
    Q.push(Point(0, 0, 1));
    while (!Q.empty()) {
        Point cur = Q.front();
        Q.pop();

        if (cur.n == N-1 && cur.m == M-1) {
            cout << cur.cnt << "\n";
            return (0);
        }

        for (int d=0; d < 4; d++) {
            int new_n = cur.n + NN[d];
            int new_m = cur.m + MM[d];
            if (!(new_n >= 0 && new_n < N && new_m >= 0 && new_m < M)) continue;
            if (map[new_n][new_m] == '1') {
                Q.push(Point(new_n, new_m, cur.cnt+1));
                map[new_n][new_m] = '0';
            }
        }
    }
}