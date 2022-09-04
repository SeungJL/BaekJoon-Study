#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;
bool isInit = true;

void dfs(int depth, int visited) {
	if (depth == N) {
		if (isInit) {
			isInit = false;
			return ;
		}
		else {
			for (auto e : arr) cout << e << " ";
			cout << "\n";
			exit(0);
		}
	}

	for (int i=arr[depth]; i<N+1; i++) {
		if ((visited & (1 << i)) == 0) {
			arr[depth] = i;
			dfs(depth+1, visited | (1 << i));
			arr[depth] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int input; 

	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> input;
		arr.push_back(input);
	}

	dfs(0, 0);
	cout << "-1\n";
	
	
}
