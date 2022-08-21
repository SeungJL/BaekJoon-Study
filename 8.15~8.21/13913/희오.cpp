// BOJ 13913

#include <iostream>
#include <queue>

using namespace std;

typedef enum _Next {
	Left = 0,
	Right,
	Jump,
	Next_size
} Next;

int move(int cur, int next) {
	switch (next) {
		case Left:
			return (cur - 1);
		case Right:
			return (cur + 1);
		case Jump:
			return (cur * 2);
	}
	return cur;
}

void print_res(int cur, vector<int> from) {
	vector<int> route;

	while (cur >= 0) {
		route.push_back(cur);
		cur = from[cur];
	}

	cout << route.size() - 1 << "\n";
	for (auto it = route.end()-1; it >= route.begin(); it--) {
		cout << *it << " ";
	} 
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int N, K;
	cin >> N >> K;

	if (N >= K) {
		cout << N - K << "\n";
		while (N >= K) {
			cout << N-- << " ";
		}
		cout << "\n";
	}
	else {
		vector<int> from(100001, -2);
		queue<int> Q;

		Q.push(N);
		from[N] = -1;
		while(!Q.empty()) {
			int cur = Q.front();
			Q.pop();

			for(int i = Left; i < Next_size; i++) {
				int next = move(cur, i);
				if (next == K) {
					from[next] = cur;
					print_res(next, from);
					return 0;
				}
				if (0 <= next && next <= 100000 && from[next] == -2) {
					from[next] = cur;
					Q.push(next);
				}
			}
		}
	}
}