#include <iostream>
#define MAX 2200
using namespace std;

int n;
int answer[3];
int paper[MAX][MAX];

/**
* @brief (x,y) 점으로부터 size 까지의 값이 모두 같은지 확인한다.
* @return {bool} 모두 같다면 true, 아니라면 false
*/
bool check(int x,int y,int size) {
	int start = paper[x][y];
	for (int i = x; i < x+size; i++) {
		for (int j = y; j < y+size; j++) {
			if (start != paper[i][j]) return false;
		}
	}
	return true;
}

/**
* @brief (x,y) 점으로부터 size까지 확인하고, 분리한다
*/
void divide(int x, int y, int size) {
	if (check(x, y, size)) {
		answer[paper[x][y] + 1]++;
	}
	else {
		int nextsize = size / 3; //사이즈를 줄여서 분할한다
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(x + nextsize * i, y + nextsize * j, nextsize);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	divide(0, 0, n);
	cout << answer[0] << "\n";
	cout << answer[1] << "\n";
	cout << answer[2] << "\n";
}
