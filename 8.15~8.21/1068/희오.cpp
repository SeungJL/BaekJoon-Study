// BOJ 1068

#include <iostream>
#include <vector>

using namespace std;

int N, removed;
int parent[50];
vector<int> childern[50];
int res;

void dfs(int cur) {

	bool isLeaf = true;
	for (auto e : childern[cur]) {
		if (e != removed) {
			isLeaf = false;
			dfs(e);
		}
	}

	if (isLeaf == true) res++;

	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int root;

	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> parent[i];
		if (parent[i] != -1)
			childern[parent[i]].push_back(i);
		else
			root = i;
	}
	cin >> removed;

	if (removed == root) {
		cout << "0\n";
		return 0;
	}

	dfs(root);
	cout << res << "\n";
	
}