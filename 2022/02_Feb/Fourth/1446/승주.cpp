#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>

using namespace std;
multimap<pair<int, int>, int> m; // 시작과 끝의 pair 에 해당하는 value 값을 담고 있음
vector <pair<int, int>>V; // 시작과 끝을 pair로 담고 있음
multimap<pair<int, int>, int>::iterator iter;
vector <int> V2;
int D;
int Min = 1000000;
void DFS(int pos, int cnt) {
	if (pos == D) {
		if (cnt < Min) {
			Min = cnt;
		}
		return;
	}
	if (pos > D) {
		return;
	}
	if (cnt > Min) {
		return;
	}

	if (find(V2.begin(), V2.end(), pos) != V2.end()) {
		int i = 0;

		while (1) {
			if (pos == V[i].first) {
				for (auto iter = m.lower_bound(make_pair(V[i].first, V[i].second)); iter != m.upper_bound(make_pair(V[i].first, V[i].second)); iter++) {
					DFS(iter->first.second, cnt + iter->second);
				}
			}

			if (i == V.size() - 1) {
				break;
			}
			i++;
		}
	}
	DFS(pos + 1, cnt + 1);
}

int main() {
	int N;
	cin >> N >> D;
	int a, b, c;
	pair <int, int> P;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		P = make_pair(a, b);
		V.push_back(P);
		V2.push_back(a);
		m.insert(pair<pair<int, int>, int>(P, c));
	}
	sort(V.begin(), V.end());
	DFS(0, 0);
	cout << Min;
}
