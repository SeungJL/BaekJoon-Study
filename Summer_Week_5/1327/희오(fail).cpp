// BOJ 1327

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string my_swap(string str, int s, int e) {
	while (s < e) {
		char tmp = str[s];
		str[s] = str[e];
		str[e] = tmp;
		s++; e--;
	}
	return (str);
}

bool my_check(string s, vector<string> ch[]) {
	for (auto e : ch[s[0]-'0'])
		if (e == s) return true;
	return false;
}

int solve(int N, int K, string init, string ans) {
	if (init == ans)
		return (0);

	queue<pair<string, int>> Q;
	vector<string> ch[N+1]; 
	Q.push(make_pair(init, 0));
	ch[init[0] - '0'].push_back(init);

	while (!Q.empty()) {
		string cur_str = Q.front().first;
		int cur_cnt = Q.front().second;
		Q.pop();

		for (int s=0; s<=N-K; s++) {
			string new_str = my_swap(cur_str, s, s+K-1);
			if (new_str == cur_str) continue;
			if (new_str == ans) return (cur_cnt + 1);
			if (my_check(new_str, ch)) continue;
			Q.push(make_pair(new_str, cur_cnt + 1));
			ch[new_str[0] - '0'].push_back(new_str);
		}
	}
	return (-1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int N, K;
	cin >> N >> K;

	string init_str, ans_str;
	for (int i=0; i<N; i++) {
		int tmp;
		cin >> tmp;
		init_str += tmp + '0';
		ans_str += (i + 1) + '0';
	}

	cout << solve(N, K, init_str, ans_str) << "\n";
}
