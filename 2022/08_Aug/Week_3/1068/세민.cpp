#include <iostream>
#include <vector>

using namespace std;

int N, cut;
vector<int> v[51];
int root;
int ans;

void dfs(int node) {
	bool leaf = true;
	for (auto ch : v[node]) {
		if (ch == cut)
		{
			continue;
		}
		else {
			leaf = false;
			dfs(ch);
		}
	}

	if (leaf)
	{
		ans++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int parent;
		cin >> parent;
		if (parent == -1)
		{
			root = i;
		}
		else {
			v[parent].push_back(i);
		}
	}

	cin >> cut;
	if (cut == root)
	{
		cout << 0;
	}
	else {
		dfs(root);
		cout << ans;
	}
}