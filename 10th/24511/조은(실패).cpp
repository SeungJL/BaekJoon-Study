#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> q_or_stk(N), initial(N);
	for(int i=0; i<N; i++) cin >> q_or_stk[i];
	for(int i=0; i<N; i++) cin >> initial[i];

	int M;
	cin >> M;
	vector<int> input(M);
	for(int i=0; i<M; i++) cin >> input[i];


	while(--N >= 0) {
		if(q_or_stk[N] == 1) continue;
		cout << initial[N] << ' ';
		M--;
	}
	for(int i=0; i<M; i++) {
		cout << input[i] << ' ';
	}

	return 0;
}