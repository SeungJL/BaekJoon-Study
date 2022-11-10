#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int k;
char c[10];
bool visited[10];
vector<string> v;

bool check(string num) {
	for (int i = 0; i < k; ++i) {
		if (c[i] == '>') {
			if (num[i] < num[i + 1]) return false;
		}
		if (c[i] == '<') {
			if (num[i] > num[i + 1]) return false;
		}
	}
	return true;
}

void dfs(int cnt, string num) {
	if (cnt == k + 1) {
		if (check(num)) v.push_back(num);
		return;
	}
	for (int i = 0; i < 10; ++i) {
		if (visited[i]) continue;
		visited[i] = true;
		dfs(cnt + 1, num + to_string(i));
		visited[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> c[i];
	}
	dfs(0, "");
	auto MIN = min_element(v.begin(), v.end());
	auto MAX = max_element(v.begin(), v.end());
	cout << *MAX << '\n' << *MIN;
	return 0;
}