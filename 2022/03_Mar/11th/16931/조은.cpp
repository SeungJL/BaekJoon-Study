#include <iostream>
using namespace std;

int cube[101][101];

int main(void) {
	int N, M;
	cin >> N >> M;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			cin >> cube[i][j];
	// 입력

	int ans = 2*N*M;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(cube[i][j] > cube[i][j-1]) ans += (cube[i][j] - cube[i][j-1]);
			if(cube[i][j] > cube[i-1][j]) ans += (cube[i][j] - cube[i-1][j]);
			if(cube[i][j] > cube[i][j+1]) ans += (cube[i][j] - cube[i][j+1]);
			if(cube[i][j] > cube[i+1][j]) ans += (cube[i][j] - cube[i+1][j]);
		}
	}
	cout << ans;

	return 0;
}