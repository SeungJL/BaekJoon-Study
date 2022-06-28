#include <iostream>
using namespace std;

int N;
int arr[17][17];
int dx[3] = { 1, 0, 1 }; // 가로, 세로, 대각선 순
int dy[3] = { 0, 1, 1 };
int ans = 0;

void dfs(int y, int x, int state) {
	// state: 가로:0, 세로:1, 대각선:2
	if((y==N-1) && (x==N-1)) ans++;
	for(int dir=0; dir<3; dir++) {
		if((state==0 && dir==1) || (state==1 && dir==0)) continue;
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if( ny<0 || nx<0 || ny>=N || nx>=N ) continue;
		if((dir==0) || (dir==1)) {
			if(arr[ny][nx] == 1) continue;
		}
		else {
			if((arr[ny][nx] == 1) || (arr[ny-1][nx] == 1) || (arr[ny][nx-1])) continue;
		}
		dfs(ny, nx, dir);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 1, 0);
	cout << ans;

	return 0;
}