#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[15][15] = { 0, };
int copy_map[15][15] = { 0, };
bool visited[15][15] = { false };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<pair<int, int>> viruses;
vector<pair<int, int>> walls;
queue<pair<int ,int>> q;
int answer = 0;

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int input;
            cin >> input;

            if(input == 2) {
                viruses.push_back({ i, j });
            } else if(input == 0) {
                walls.push_back({ i, j });
            } 

            map[i][j] = input;
            copy_map[i][j] = input;
            
        }
    }

    vector<int> comb(walls.size());

    for(int i = 0; i < 3; i++)
        comb.push_back(1);

    do {
        for(int i = 0; i < comb.size(); i++) {
            if (comb[i] == 1) {
                // 3곳에 벽 세우기
                map[walls[i].first][walls[i].second] = 1;
            }            
        }

        // bfs
        for(int j=0; j<viruses.size(); j++) {
            q.push({ viruses[j].first, viruses[j].second });
            visited[viruses[j].first][viruses[j].second] = true;
        }

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k=0; k<4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < n && nx >= 0 && ny < m && ny >= 0 && visited[nx][ny] == false && map[nx][ny] == 0) {
                    q.push({ nx, ny });
                    visited[nx][ny] = true;
                    map[nx][ny] = 2;
                }
            }
        }

        int count = 0;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(map[j][k] == 0){ 
                    count++;
                }
                map[j][k] = copy_map[j][k];
                visited[j][k] = false;
            }
        }
        if(count > answer) answer = count;
 
    } while(next_permutation(comb.begin(), comb.end()));

    cout << answer;


}