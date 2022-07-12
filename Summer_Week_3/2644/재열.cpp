#include <iostream>
#include <vector>

using namespace std;

int n, person1, person2, m;
vector<int> table[101];
int is_visited[101];

int dfs(int now, int target, int depth) {
	is_visited[now] = 1;
	if (now == target) {
		is_visited[now] = 0;
		return depth;
	}
	int temp, result=9999999;
	for (int i = 0; i < table[now].size(); i++) {
		if (!is_visited[table[now][i]]) {
			temp = dfs(table[now][i], target, depth+1);
			if (temp != -1)
				result = min(result, temp);
		}
	}
	is_visited[now] = 0;
	if (result < 9999999)
		return result;
	else 
		return -1;
}

int main() {
	cin >> n >> person1 >> person2 >> m;
	for (int i = 0; i <= n; i++)
		table[i] = vector<int>();
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		table[x].push_back(y);
		table[y].push_back(x);
	}
	cout << dfs(person1, person2, 0) << endl;
	return 0;
}
