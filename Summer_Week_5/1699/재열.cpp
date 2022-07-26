#include <iostream>
#include <cmath>	

using namespace std;

int dp[100001];

int get_min(int n) {
	if (dp[n]) return dp[n];
	if (n == 0) return 0;
	if (n == 1) return 1;

	int temp;
	temp = 1 + get_min(n - pow((int)sqrt(n), 2));
	for (int i = (int)sqrt(n); i >= 1; i--) {
		temp = min(temp, 1 + get_min(n - pow(i, 2)));
	}
	return dp[n] = temp;
}

int main() {
	int N;
	cin >> N;
	cout << get_min(N) << endl;
	return 0;
}
