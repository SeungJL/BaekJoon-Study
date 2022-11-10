#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int T, N;
	int visit[1001] = {};
	int arr[1001];
	int cnt = 0;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 1; j <= N; j++) {
			cin >> arr[j];
		}
		for (int j = 1; j <= N; j++) {

			if (visit[j] == 0) {
				int k = j;
				while (1) {
					if (visit[k] == 1) {
						cnt++;
						break;
					}
					visit[k] = 1;
					k = arr[k];
				}
			}
		}
		cout << cnt << '\n';
		cnt = 0;
		memset(visit, 0, sizeof(visit));

	}
}