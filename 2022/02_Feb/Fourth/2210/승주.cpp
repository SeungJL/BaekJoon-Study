#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>

using namespace std;
vector <int> V;
char arr[5][5] = {};

void DFS(int a, int b, int cnt, string str) {
	cnt++;
	if (a < 0 || a>4 || b < 0 || b>4) {
		return;
	}
	str += arr[a][b];
	if (cnt == 6) {
		V.push_back(stoi(str));
		return;
	}
	DFS(a + 1, b, cnt, str);
	DFS(a - 1, b, cnt, str);
	DFS(a, b + 1, cnt, str);
	DFS(a, b - 1, cnt, str);

}


int main() {


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			DFS(i, j, 0, " ");
		}
	}
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
	cout << V.size();
}