#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, m;
	int arrMax[2][5] = {};
	int arrMin[2][5] = {};

	cin >> N;
	int a, b, c;
	if (N == 1) {
		cin >> a >> b >> c;
		cout << max({ a,b,c }) << " " << min({ a,b,c });
		return 0;
	}
	arrMin[0][0] = 10000000; arrMin[0][4] = 10000000; arrMin[1][0] = 10000000; arrMin[1][4] = 10000000;
	int check = 1;
	int flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> m;
			if (i == 0) {
				arrMax[0][j] = m;
				arrMin[0][j] = m;
			}
			else {
				if (flag == 0) check = 1;
				else check = 0;
				arrMax[flag][j] = m + max({ arrMax[check][j - 1],arrMax[check][j],arrMax[check][j + 1] });
				arrMin[flag][j] = m + min({ arrMin[check][j - 1],arrMin[check][j],arrMin[check][j + 1] });
			}
		}
		if (i == N - 1) {
			cout << max({ arrMax[flag][1],arrMax[flag][2],arrMax[flag][3] }) << " ";
			cout << min({ arrMin[flag][1],arrMin[flag][2],arrMin[flag][3] });
		}
		if (flag == 0)flag = 1;
		else flag = 0;
	}
	return 0;
}