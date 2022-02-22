#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>

using namespace std;

bool arr[51][51] = {};
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

int cnt = 0;
int w, h;
void DFS(int i, int j) {
	arr[i][j] = 0;
	for (int a = 0; a < 8; a++) {
		if (j + dx[a] >= 0 && j + dx[a] < w && i + dy[a] >= 0 && i + dy[a] < h) {
			if (arr[i + dy[a]][j + dx[a]] == 1) {
				DFS(i + dy[a], j + dx[a]);
			}
		}
	}
}

int main() {

	while (cin >> w >> h) {
		if (w == 0 && h == 0) {
			return 0;
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];

			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 1) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		cnt = 0;
		arr[51][51] = {};

	}

}