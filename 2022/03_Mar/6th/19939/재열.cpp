#include <iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	//K개의 바구니에 대해, 각각 1개,2개,3개,...K개씩 공을 나눠줌.
	for (int i = K; i >= 1; i--) {	
		N -= i;
		if (N < 0) {
			cout << -1 << endl;
			return 0;
		}
	}

	//남은 공의 개수가 K로 나누어떨어지면, 기본값인 K-1이 결과값이다. 아니라면, 거기에 1을 더한 값이 결과값이다.
	if (N % K == 0) cout << K-1 << endl;
	else cout << K << endl;

	return 0;
}