#include <iostream>

using namespace std;
int A[1000][1000];
int main() {
	int ans[301][301];
	int H, W, X, Y;
	cin >> H >> W >> X >> Y;
	for (int i = 0; i < X + H; i++) {
		for (int j = 0; j < W + Y; j++) {
			cin >> A[i][j];

			if (i >= X && j >= Y && i < H && j < W) {
				ans[i][j] = A[i][j] - ans[i - X][j - Y]; // 겹치는 경우
			}
			else {
				if (i < H && j < W) {
					ans[i][j] = A[i][j]; // 안 겹치고, 이전 원본 배열과 같은 index
				}
				else { // 안 겹치지만, 이전 원본 배열과 다른 index(이동된 배열에서 추론)
					if (i - X < 0 || j - Y < 0) {
						ans[i - X][j - Y] = 0;
					}
					else {
						ans[i - X][j - Y] = A[i][j];
					}
				}
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}