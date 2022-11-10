// BOJ 1062

#include <iostream>

using namespace std;


int N, K;
int letters[50];
int res = 0;

int check_n_count(int comb) {
	int word_cnt = 0;
	for (int i=0; i<N; i++) {
		if (((letters[i] & comb) ^ letters[i]) == 0) word_cnt++;
	}

	return (word_cnt);
}

void dfs_combination(int depth, int comb, int last_letter) {
	if (depth == K - 5) {
		int cnt = check_n_count(comb);
		if (cnt > res) res = cnt;
	}

	for (int i=last_letter + 1; i<26; i++) {
		if (comb & (1 << i)) continue;
		dfs_combination(depth + 1, comb | (1 << i), i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	cin >> N >> K;

	if (K < 5) {
		cout << "0\n";
		return 0;
	}

	string input;
	for(int i=0; i<N; i++) {
		cin >> input;
		for (char e : input) {
			letters[i] = letters[i] | (1 << (e - 'a'));
		}
	}

	int comb = 0 | (1 << ('a' - 'a')) | (1 << ('c' - 'a')) | (1 << ('i' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a'));
	dfs_combination(0, comb, 0);

	cout << res << "\n";
	
}