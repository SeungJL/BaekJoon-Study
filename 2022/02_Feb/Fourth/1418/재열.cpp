#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	bool isNotPrime[100001] = {false,};
	for (int i = 2; i <= 100000; i++) {
		if (isNotPrime[i]) continue;
		else {
			int j = 2;
			while (i * j <= 100000) {
				isNotPrime[i*j] = true;
				j++;
			}
		}
	}

	// k보다 큰 소수로 나누어떨어지지 않으면 k세준수
	// k보다 큰 소수의 배수 제거
	bool signal[100001] = {false,};		//이미 체크한 적 있는지..
	int count = 0;
	for (int i = k+1; i <= n; i++) {		
		if (!isNotPrime[i]) {		
			//여기까지 진입했으면, i는 k보다 큰 소수
			int j = 1;
			while (i * j <= n) {
				if (!signal[i*j]) {
					count++;
					signal[i*j] = true;
				}
				j++;
			}
		}
	}
	cout << n - count << endl;

	return 0;
}