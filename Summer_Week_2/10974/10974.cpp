#include <iostream>
#include <deque>

using namespace std;

int N;
bool is_visited[9];
deque<int> nums;

void dfs(int now, int depth) {
	nums.push_back(now);
	is_visited[now] = true;
	if (depth == N) {
		for (int i = 0; i < N; i++) 
			cout << nums[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (!is_visited[i]) 
				dfs(i, depth+1);
		}
	}
	nums.pop_back();
	is_visited[now] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		is_visited[i] = false;
	}
	for (int i = 1; i <= N; i++) {
		dfs(i, 1);
	}
	return 0;
}