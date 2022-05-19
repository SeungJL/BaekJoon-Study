#include <iostream>

using namespace std;


int N;
long long ans[101] = {};

long long DP(int n) {

	if (ans[n] != 0) { return ans[n]; }
	return ans[n] = DP(n - 1) + DP(n - 2);
}


int main() {
	ans[1] = 1;
	ans[2] = 1;
	ans[3] = 2;
	cin >> N;
	cout << DP(N);
}