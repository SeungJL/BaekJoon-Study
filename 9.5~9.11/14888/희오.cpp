#include <iostream>
#include <functional>

using namespace std;

function<int (int, int)> funcs[4] = { [](int a, int b) { return a + b; },
									  [](int a, int b) { return a - b; },
									  [](int a, int b) { return a * b; },
									  [](int a, int b) { if (a >= 0) return a / b; 
						  								 else  	   	 return -(-a / b); } };
int op_cnt[4];

int N;
int nums[11] = {};
int max_res = -2147000000, min_res = 2147000000;

void dfs(int depth, int res) {
	if (depth == N) {
		if (res > max_res) max_res = res;
		if (res < min_res) min_res = res;
		return ;
	}

	for (int i = 0; i < 4; i++) {
		if (op_cnt[i] > 0) {
			op_cnt[i]--;
			dfs(depth + 1, funcs[i](res, nums[depth]));
			op_cnt[i]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> nums[i];
	}
	for (int i=0; i<4; i++) {
		cin >> op_cnt[i];
	}

	dfs(1, nums[0]);
	cout << max_res << "\n" << min_res << "\n";
}