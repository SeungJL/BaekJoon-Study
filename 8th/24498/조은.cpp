#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> input(N);
	for(int i=0; i<N; i++) cin >> input[i];

	vector<int> v(N);
	v[0] = input[0];
	v[N-1] = input[N-1];
	for(int i=1; i<N-1; i++) {
		v[i] = input[i] + min(input[i-1], input[i+1]);
	}
	
	int max = *max_element(v.begin(), v.end());
	cout << max;

	return 0;
}