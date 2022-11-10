#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N, M;
	int x;
	cin >> T;

	map<int, int> m1;

	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> x;
			m1[x]++;
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> x;
			if (m1.find(x) != m1.end()) {
				cout << 1;
			}
			else {
				cout << 0;
			}
			cout << '\n';
		}
		m1.clear();
	}
}