#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, M;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		unordered_set<int> uset;
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			uset.insert(temp);
		}
		cin >> M;
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			if (uset.find(temp) != uset.end()) 
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
	return 0;
}