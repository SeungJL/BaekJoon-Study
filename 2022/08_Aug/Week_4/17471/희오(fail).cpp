#include <iostream>
#include <vector>

using namespace std;

#define my_abs(n) (n >= 0) ? n : -n

int N;
int population[10] = {};
bool G[10][10] = {};

bool check_isOneSet(vector<int> subset) {
	int ch = 0;
	ch = ch | (1 << subset[0]);
	int cnt = subset.size() - 1;
	
	for (int i=0; i<subset.size()-1; i++) {
		if ((ch & (1 << subset[i])) == 0) continue;
		for (int j=i+1; j<subset.size(); j++) {
			if ((ch & (1 << subset[j])) == 1) continue;
			if (G[i][j] == true) {
				ch = ch | (1 << subset[j]);
				cnt--;
			}
		}
	}

	if (cnt == 0) return true;
	return false;
}

int solve() {
	int res = 100000;
	
	for (int subset = 1; subset < (1 << (N-1)); subset++) {
		vector<int> subsets[2];
		int popul_sum[2] = {};
		bool isConnected = true;
		for (int i=0; i<N; i++) {
			if ((subset & (1 << i)) == 0) {
				subsets[0].push_back(i);
				popul_sum[0] += population[i];
			}
			else {
				subsets[1].push_back(i);
				popul_sum[1] += population[i];
			}
		}

		for (int set_i=0; set_i<2; set_i++) {
			isConnected = check_isOneSet(subsets[set_i]);
			if (!isConnected) break;
		}
		
		if (isConnected) {
			int diff = my_abs(popul_sum[0] - popul_sum[1]);
			if (diff < res) res = diff;
		}
	}

	return res;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "rt", stdin);

	cin >> N;
	for(int i=0; i<N; i++) cin >> population[i];
	for(int i=0; i<N; i++) {
		int cnt, j;
		cin >> cnt;
		while (cnt--) {
			cin >> j;
			G[i][j] = true;
		}
	}

	cout << solve() << "\n";
	
}