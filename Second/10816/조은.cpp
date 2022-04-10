#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N;
	vector<int> v(N);
	for(int i=0; i<N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	
	cin >> M;
	int m;
	while(M--) {
		cin >> m;
		cout << upper_bound(v.begin(), v.end(), m) - lower_bound(v.begin(), v.end(), m) << ' ';
	}

	return 0;
}