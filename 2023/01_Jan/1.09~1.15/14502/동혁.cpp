#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int N, M;
int virusMap[8][8];
int visited[8][8] = {0, };
int maxSpace = -1;
int maxCandi = -1;
int wallNum = 0;
int infectedSpace = 0;
vector<pair<int, int>> virusPos;
vector<pair<int, int>> spacePos;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int x, int y) {
    // 범위 넘어설 때
    if(x < 0 || y < 0 || x >= N || y >= M) {
        return;
    } 
    

    // 벽일 때
    if(virusMap[x][y] == 1 || visited[x][y]) {
        return;
    }
    


    //
    
    if(virusMap[x][y] == 0 && !visited[x][y]) {
        infectedSpace++;
        
    }

    visited[x][y] = 1;

    for(int i = 0; i < 4; i++) {
        int xPos = x + dx[i];
        int yPos = y + dy[i];
       
        bfs(xPos, yPos);
    
    }

    return;
}

int main() {
    fastio;
    
    // 입력
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> virusMap[i][j];
            if(virusMap[i][j] == 2) {
                virusPos.push_back(make_pair(i, j));
                continue;
            }
            if(virusMap[i][j] == 0) {
                spacePos.push_back(make_pair(i, j));
                continue;
            }
            wallNum++;
        }
    }
    
    // 로직
    for(int i = 0; i < spacePos.size(); i++) {
        virusMap[spacePos[i].first][spacePos[i].second] = 1;
        for(int j = i + 1; j < spacePos.size(); j++) {
            virusMap[spacePos[j].first][spacePos[j].second] = 1;
            for(int k = j + 1; k < spacePos.size(); k++) {
                virusMap[spacePos[k].first][spacePos[k].second] = 1;
            
                infectedSpace = 0;

                for(int l = 0; l < virusPos.size(); l++) {
                     bfs(virusPos[l].first, virusPos[l].second);
                }
                maxCandi = N * M - virusPos.size() - wallNum - infectedSpace - 3;
                maxSpace = max(maxSpace, maxCandi);
                memset(visited, 0, sizeof(visited));
                virusMap[spacePos[k].first][spacePos[k].second] = 0;
            }
            virusMap[spacePos[j].first][spacePos[j].second] = 0;
        }
        virusMap[spacePos[i].first][spacePos[i].second] = 0;
    }

    cout << maxSpace;
    return 0;
}