#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, N, M;
	cin >> T;
	while(T--) {
		cin >> N;
		vector<int> v(N);
		for(int i=0; i<N; i++) cin >> v[i];
		sort(v.begin(), v.end());
	
		cin >> M;
		int n;
		while(M--) {
			cin >> n;
			cout << binary_search(v.begin(), v.end(), n) << '\n';
		}
	}
	
	return 0;
}