#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int N, K;
string str;
map <string, bool> visited;

int bfs(string s)
{
	string ans = s;
	sort(ans.begin(), ans.end());

	queue<pair<string, int>> q;
	q.push(make_pair(s, 0));
	visited[s] = true;

	while (!q.empty()) {
		string cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == ans) return cnt;
		for (int i = 0; i <= N - K; i++) {
			string tmp = cur.substr(i, K);
			reverse(tmp.begin(), tmp.end());
			string next = cur.substr(0, i);
			next += tmp;
			next += cur.substr(i + K);
			if (!visited.count(next)) {
				q.push(make_pair(next, cnt + 1));
				visited[next] = true;
			}
		}
	}

	return -1;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		char ch;
		cin >> ch;
		str += ch;
	}

	cout << bfs(str);

	return 0;
}