#include <iostream>
#include <queue>

using namespace std;

#define loc first 
#define cnt second 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int N;
	int maze[1000] = {};

	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> maze[i];
	}

	if (N == 1) {
		cout << "0\n";
		return 0;
	}

	queue<pair<int, int>> Q;
	bool visited[1000] = {};
	
	Q.push(make_pair(0, 0));
	visited[0] = true;

	while (!Q.empty()) {
		int cur_loc = Q.front().loc;
		int cur_cnt = Q.front().cnt;
		Q.pop();

		for (int i=1; i<=maze[cur_loc]; i++) {
			int next = cur_loc + i;
			if (next == N - 1) {
				cout << cur_cnt + 1 << "\n";
				return 0;
			}
			if (next < 1000 && visited[next] == false) {
				visited[next] = true;
				Q.push(make_pair(next, cur_cnt + 1));
			}
		}
	}
	
	cout << "-1\n";
	
}
