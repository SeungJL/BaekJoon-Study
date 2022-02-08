#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>
using namespace std;
int n;
vector <int> V;
int Min = 100000;
int x, y;

int main() {


	int visit[10001] = {};
	for (int i = 2; i <= 10000; i++) {
		if (visit[i] == 0) {
			int j = 2;
			while (1) {
				if (i * j > 10000) { break; }
				visit[i * j] = 1;
				j++;
			}
		}
	}
	for (int i = 2; i <= 10000; i++) {
		if (visit[i] == 0) {
			V.push_back(i);
		}
	}
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		int x = n / 2;
		while (1) {
			if (visit[x] == 0 && visit[n - x] == 0) {
				cout << x << " " << n - x << endl;
				break;
			}
			else {
				x--;
			}
		}
	}
}
