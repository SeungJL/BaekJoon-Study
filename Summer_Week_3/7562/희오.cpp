#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int r, c, cnt;
    Point(int _r, int _c, int _cnt) : r(_r), c(_c), cnt(_cnt) {}
};

// 나이트가 이동할 수 있는 방향, (r, c) -> (r + R[i], c + C[i])
int R[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int C[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool ch[300][300]; // 보드 각 지점의 방문 여부 정보, true-visited

/* BFS로 문제를 푸는 함수
 * l - 보드의 크기, from - 출발하는 지점, to - 도착 지점
 * 출발지점에서부터 도착지점까지 이동한 칸 수를 return
 */
int solve(int l, pair<int, int> from, pair<int, int> to) {
    // 예외처리 - 출발지점과 도착지점이 같을 경우
    if (from.first == to.first && from.second == to.second)
        return 0;

    // init (ch배열 0으로 초기화, queue 초기화)
    for (int i=0; i<l; i++) {
        for (int j=0; j<=l; j++)
            ch[i][j] = false;
    }
    queue<Point> Q;
    Q.push(Point(from.first, from.second, 0));
    
    while (!Q.empty()) {
        Point cur = Q.front();
        Q.pop();

        for (int d=0; d<8; d++) {
            int new_r = cur.r + R[d], new_c = cur.c + C[d];
            if (new_r == to.first && new_c == to.second)
                return (cur.cnt + 1);
            if (new_r < 0 || new_r >= l || new_c < 0 || new_c >= l) continue;
            if (ch[new_r][new_c]) continue;
            Q.push(Point(new_r, new_c, cur.cnt + 1));
            ch[new_r][new_c] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    int TC;
    cin >> TC;

    while (TC--) {
        int l, r1, c1, r2, c2;
        cin >> l >> r1 >> c1 >> r2 >> c2;
        cout << solve(l, make_pair(r1, c1), make_pair(r2, c2)) << "\n";
    }
}