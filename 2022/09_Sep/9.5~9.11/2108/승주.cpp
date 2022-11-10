#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N; // 홀수
	int x; //-4000~4000
	int list[500001];
	int count_plus[4001] = { 0 };
	int count_minus[4001] = { 0 };
	int cnt = 0;
	int Max = -10000;
	vector <int> V;

	for (int i = 0; i < N; i++) {
		cin >> list[i];
		cnt += list[i];
		if (list[i] > 0) {
			count_plus[list[i]]++;
		}
		else {
			int y = -list[i];
			count_minus[y]++;
		}
	}
	cout << floor((double)cnt / (double)N + 0.5) << endl;
	sort(list, list + N);
	cout << list[(N - 1) / 2] << endl;
	int k;
	int k2;
	int p = 0;
	for (int i = 0; i < 4001; i++) {
		if (count_plus[i] > Max) {
			Max = count_plus[i];
			k = i;
			V.clear();
			V.push_back(i);
			p = 1;
		}
		if (count_minus[i] > Max) {
			Max = count_minus[i];
			k = -i;
			V.clear();
			V.push_back(k);
			p = 1;
		}
		if (p == 1) {
			p = 0;
			continue;
		}
		if (count_plus[i] == Max) {
			V.push_back(i);
		}
		if (count_minus[i] == Max) {
			V.push_back(-i);
		}
	}

	if (V.size() > 1) {
		sort(V.begin(), V.end());
		cout << V[1] << endl;
	}
	else {
		cout << k << endl;
	}
	cout << list[N - 1] - list[0];

}