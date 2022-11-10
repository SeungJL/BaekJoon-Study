#include <iostream>

using namespace std;

int arr[51][51];
int dy[4] = { 1,0,-1,0 };	//위, 아래
int dx[4] = { 0,-1,0,1 };	//오른쪽, 왼쪽

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x = 0, y = 0;	
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	int len = 1, cnt = 1;
	if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {
		arr[x - r1][y - c1] = cnt;
	}
	++cnt;

	int curLen = 0;
	int dir = 0;

	while (arr[0][0] == 0 || arr[r2 - r1][0] == 0 || arr[0][c2 - c1] == 0 || arr[r2 - r1][c2 - c1] == 0) {
		x += dx[dir];
		y += dy[dir];

		if (x >= r1 && x <= r2 && y >= c1 && y <= c2) {	//주어진 범위 내의 결과만 배열에 저장
			arr[x - r1][y - c1] = cnt;
		}
		++cnt;
		++curLen;

		if (curLen == len) {
			curLen = 0;
			++dir;
			dir %= 4;
			if (dir == 0 || dir == 2) ++len;
		}
	}

	int space = 0;	//공백의 길이
	while (cnt != 0) {
		cnt /= 10;
		++space;
	}

	for (int i = 0; i <= r2 - r1; ++i) {	//배열 출력
		for (int j = 0; j <= c2 - c1; ++j) {
			cout.width(space);	//숫자의 길이(공백 포함)를 같게 한다.
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}