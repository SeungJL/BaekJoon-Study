#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
	int num;
	int gold, silver, bronze;
}nation;

bool cmp(nation &x, nation &y) {
	if (x.gold == y.gold) {
		if (x.silver == y.silver) {
			return x.bronze > y.bronze;
		}
		else { return x.silver > y.silver; }
	}
	else { return x.gold > y.gold; }
}

int main() {
	int N, K;
	cin >> N >> K;
	vector<nation> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].num >> v[i].gold >> v[i].silver >> v[i].bronze;
	}

	sort(v.begin(), v.end(), cmp);

	int rank = 0;
	for (int i = 0; i < N; i++) {
		if (!((v[i].gold == v[i-1].gold) && (v[i].silver == v[i-1].silver) && (v[i].bronze == v[i-1].bronze))) {
			rank = i+1;
		}
		if (v[i].num == K) {
			cout << rank;
			break;
		}
	}

	return 0;
}