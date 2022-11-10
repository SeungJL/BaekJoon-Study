#include <iostream>

using namespace std;

unsigned long long dp[31] = {0,};

unsigned long long factorial(int n) {
	if (n == 0) return 1;
	if (n == 1) return 1;

	if (dp[n] != 0) return dp[n];
	return dp[n] = n * factorial(n-1);
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;

		//사이트가 많은 쪽에서 사이트가 적은 쪽의 사이트 개수만큼을 선택하는 경우의 수
		//조합 
		int maxNum = max(n, m);
		int minNum = min(n, m);

		unsigned long long result = factorial(maxNum);
		unsigned long long div = factorial(maxNum-minNum)*factorial(minNum);

		//나눗셈하면 계속 0이 나와서 다음과 같이 계속 빼는 식으로 했다.
		unsigned long long count = 0;
		while (result > 0) {
			result -= div;
			count++;
		}

		cout << count << endl;
	}
	return 0;
}
