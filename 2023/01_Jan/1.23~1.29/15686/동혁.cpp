#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int N, M;
int board[51][51];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<pair<int, int>> chickenList;
int ret = 987654321;
int minDis;
int minNum;

int getDistance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}
void solve() {
    minNum = 0;
    for(pair<int, int> homePos : home) {
        minDis = 987654321;
        for(pair<int, int> chickenPos : chickenList) {
            minDis = min(minDis, getDistance(chickenPos, homePos));
            if(minDis == 1) break;
        }
        //cout << "(" << homePos.first << ",  " << homePos.second << ")" << ":  " << minDis << endl;
        minNum += minDis;
        if(minNum >= ret) return;
    }

    ret = min(ret, minNum);
}
void combi(int start) {
    if(chickenList.size() == M) {
        solve();
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++) {
        chickenList.push_back(chicken[i]);
        combi(i);
        chickenList.pop_back();
    }

    return;
}
int main() {
    fastio;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) {
                home.push_back({i, j});
            } else if(board[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }
    combi(-1);
    cout << ret;
    return 0;
}