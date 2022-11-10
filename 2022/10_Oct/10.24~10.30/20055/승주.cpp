#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K, a, b, c;
	int cnt = 0;
	int h = 0;
	int p = 0;
	cin >> N >> K;

	vector <int> V; //내구도
	vector<bool>check(N, 0); //로봇 위치

	for (int i = 0; i < 2 * N; i++) {
		cin >> a;
		V.push_back(a);
	}

	while (1) {
		cnt++;
		b = V.back();
		V.pop_back();
		V.insert(V.begin(), b);
		check.insert(check.begin(), 0);
		check.pop_back();
		if (check[N - 1] == 1) {
			check[N - 1] = 0;
		}
		//2N개 이하일때
		int i = N - 1;

		while (1) {
			if (check[i] == 1 && V[i + 1] > 0 && check[i + 1] == 0) {

				check[i] = 0;
				check[i + 1] = 1;
				V[i + 1]--;
				if (V[i + 1] == 0) {
					h++;
				}
				if (check[N - 1] == 1) {
					check[N - 1] = 0;
				}
			}
			if (i == 0) {
				break;
			}
			i--;
		}
		if (V[0] != 0) {
			check[0] = 1;
			V[0]--;
			if (V[0] == 0) {
				h++;
			}
		}
		if (h >= K) {
			cout << cnt;
			return 0;
		}
	}

}