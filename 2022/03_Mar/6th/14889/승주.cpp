#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define min(a,b) (a<b?a:b)

using namespace std;
int N;
vector <int> V;

int S[21][21];
int Min = 1000;


void combination(vector<int>V, vector<int>comb, int r, int index, int depth) {

	if (r == 0) {
		vector<int>V2;
		V2.resize(comb.size());
		set_difference(V.begin(), V.end(), comb.begin(), comb.end(), V2.begin());

		int cnt = 0;
		int cnt2 = 0;
		for (int i = 0; i < N / 2 - 1; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				cnt += S[comb[i]][comb[j]] + S[comb[j]][comb[i]];
				cnt2 += S[V2[i]][V2[j]] + S[V2[j]][V2[i]];
			}
		}
		int z = cnt - cnt2;

		if (abs(cnt - cnt2) < Min) {
			Min = abs(z);
		}

		return;
	}
	else if (depth == N - 1 || index >= N / 2) {
		return;
	}

	combination(V, comb, r, index, depth + 1);
	comb[index] = V[depth];
	combination(V, comb, r - 1, index + 1, depth + 1);
}


int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		V.push_back(i);
	}
	int r = N / 2;
	vector<int>comb(r);

	combination(V, comb, r, 0, 0);
	cout << Min;
}