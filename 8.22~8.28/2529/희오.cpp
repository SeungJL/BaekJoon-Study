#include <iostream>

using namespace std;

int k;
char input[10] = {};
int num[10] = {};
int res[11] = {};

bool isCorrect(int depth, int i) {
	return ((input[depth-1] == '<') ? res[depth - 1] < num[i] : res[depth - 1] > num[i]);
}

bool dfs(int depth, int visited) {
	if (depth == k + 1) {
		for (int i = 0; i <= k; i++)
			cout << res[i];
		cout << "\n";
		return true;
	}

	for (int i=0; i<10; i++) {
		if ((depth == 0)
			|| ((visited & (1 << num[i])) == 0 && isCorrect(depth, i))) {
			res[depth] = num[i];
			if (dfs(depth + 1, visited | (1 << num[i]))) return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	cin >> k;
	for (int i=0; i<k; i++) {
		cin >> input[i];
	}

	for(int i=0; i<10; i++) {
		num[i] = 9 - i;
	}
	dfs(0, 0);

	for(int i=0; i<10; i++) {
		num[i] = i;
	}
	dfs(0, 0);
	
}