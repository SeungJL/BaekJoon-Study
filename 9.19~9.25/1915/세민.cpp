#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[1001][1001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("input.txt", "r", stdin);

	int n, m, cnt = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		string str;
		cin >> str;
		int len = str.length();
		for (int j = 0; j < len; ++j) {
			arr[i][j + 1] = str[j] - '0';
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (arr[i][j] == 1) {
				arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1;
				if (cnt < arr[i][j]) cnt = arr[i][j];
			}
		}
	}

	/*
	0100
	0111
	1120
	0010
	*/

	/*for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << arr[i][j];
		}
		cout << '\n';
	}*/

	cout << cnt * cnt;

	return 0;
}