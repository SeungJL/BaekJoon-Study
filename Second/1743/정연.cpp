//백준1743 음식물피하기                                                            
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int N, M, K;
int map[102][102];
bool visited[102][102];
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
vector<int> v; 
int s = 1; 
 
void DFS(int y, int x) {
    visited[y][x] = true;
 
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
 
        if (ny<0 || nx<0 || ny>N || nx>M)
            continue;
        if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
            visited[ny][nx] = true;
            s++;
            DFS(ny, nx);
        }
    }
}
 
 
int main() {
    cin >> N >> M >> K;
    for(int i=0;i i<= K ; i++){
        int r, c;
        cin >> r >> c;
        map[r][c] = 1;
    }
 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                DFS(i, j);
                v.push_back(s);
                s = 1;
            }
        }
    }
 
    sort(v.begin(), v.end(), greater<int>()); 
    cout << v[0]; 
    
    return 0;
}
