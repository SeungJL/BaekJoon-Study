// BOJ 4485 젤다

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y, rupee;
    Point(int _x, int _y, int _r) : x(_x), y(_y), rupee(_r) {}
    bool operator< (const Point &x) const {
        return (rupee > x.rupee);
    }
};

int XX[4] = {-1, 0, 1, 0};
int YY[4] = {0, 1, 0, -1};
int N;

int solve(vector<vector<int>> map, vector<vector<bool>> ch) {
    priority_queue<Point> PQ;
    PQ.push(Point(0, 0, map[0][0]));
    while (!PQ.empty()) {
        Point cur = PQ.top(); PQ.pop();

        for (int d=0; d<4; d++) {
            int new_x = cur.x + XX[d], new_y = cur.y + YY[d];
            if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N) continue;
            if (ch[new_x][new_y]) continue;
            if (new_x == N-1 && new_y == N-1) 
                return (cur.rupee + map[new_x][new_y]);
            PQ.push(Point(new_x, new_y, cur.rupee + map[new_x][new_y]));
            ch[new_x][new_y] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);

    int TC = 0;
    while (cin >> N) {
        if (N == 0) return 0;
        TC++;

        vector<vector<int>> map(N, vector<int>(N, 0));
        vector<vector<bool>> ch(N, vector<bool>(N, 0));
        for (int i=0; i<N; i++) {
           for (int j=0; j<N; j++)
                cin >> map[i][j]; 
        }

        cout << "Problem " << TC << ": " << solve(map, ch) << "\n";
    }

}