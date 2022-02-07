#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	int N, K;
	cin >> N >> K;
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	
	int i = K;
	int n = N;
	cout << "<";
	while(n--) {
		if (i <= N) {
			cout << v[i - 1];
			if (n) cout << ", ";
			v[i - 1] = 0;
		}
		else {
			cout << v[i - N - 1];
			if (n) cout << ", ";
			v[i - 1 - N] = 0;
			i = i - N;
		}

		int cnt = 0;
		while (cnt != K && n != 0) {
			if (i < N) {
				if (v[i] == 0) {}
				else cnt++;
				i++;
			}
			else {
				if (v[i - N] == 0) {}
				else cnt++;
				i = i - N + 1;
			}
		}
	}
	cout << ">";

	return 0;
}
