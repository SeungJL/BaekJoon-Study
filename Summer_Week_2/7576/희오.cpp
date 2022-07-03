#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n;
int XX[4] = {0, 1, 0, -1};
int YY[4] = {-1, 0, 1, 0};

class Tomato{
    int x, y;
    int day;

    public:
        Tomato(int _x, int _y, int _d) : x(_x), y(_y), day(_d) {};
        int get_x() { return x; }
        int get_y() { return y; }
        int get_day() { return day; }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "rt" , stdin);
  
    cin >> m >> n;

    vector<vector<int>> box(n, vector<int>(m, 0));
    queue<Tomato> Q;
    int tomato_cnt = 0;
    int max_day = 0;

    tomato_cnt = m * n;
    max_day = 0;
    for (int y=0; y<n; y++) {
        for (int x=0; x<m; x++) {
            cin >> box[y][x];
            if (box[y][x] == -1)
                tomato_cnt--;
            if (box[y][x] == 1)
                Q.push(Tomato(x, y, 0));
        }
    }

    while (!Q.empty()) {
        int top_x = Q.front().get_x();
        int top_y = Q.front().get_y();
        int top_day = Q.front().get_day();
        
        Q.pop();
        if (top_day > max_day) max_day = top_day;
        tomato_cnt--;
        if (tomato_cnt == 0) break;
        
        for (int d=0; d<4; d++) {
            int new_x = top_x + XX[d];
            int new_y = top_y + YY[d];
            if (new_x < 0 || new_x >= m) continue;
            if (new_y < 0 || new_y >= n) continue;
            if (box[new_y][new_x] == 0) {
                box[new_y][new_x] = 1;
                Q.push(Tomato(new_x, new_y, top_day + 1));
            }
        }
    }

    if (tomato_cnt > 0) cout << "-1\n";
    else cout << max_day << "\n";
}