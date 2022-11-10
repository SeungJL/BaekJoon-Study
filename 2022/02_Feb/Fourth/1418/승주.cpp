#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
	int check[100001] = { 1,1, };

	for (int i = 2; i <= 100000; i++) {
		if (check[i] == 0) {
			int j = 2;
			while (i * j <= 100000) {
				check[i * j] = 1;
				j++;
			}
		}
	}
	// check에 0의 값이 소수의 위치
	vector <int> V;
	for (int i = 2; i <= 100000; i++) {
		if (check[i] == 0) {
			V.push_back(i);
		}
	}
	V.push_back(100001);
	int N, K;
	cin >> N;
	cin >> K;
	int i = 0;
	int pos = 0;
	while (1) {
		if (V[i] == K) {
			pos = i;
			break;
		}
		else if (V[i] > K) {
			pos = i - 1;
			break;
		}
		i++;
	}
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		int j = pos + 1;
		while (1) {
			if (V[j] > i) {
				cnt++;
				break;
			}
			if (i % V[j] == 0) {
				break;
			}
			j++;
		}
	}
	cout << cnt + 1;
}
