#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> isPrime;

void findPrimeNum() {		//2부터 10000까지 어떤게 소수인지 판단 (에라스노테네스의 채 알고리즘)
	for (int i = 2; i < isPrime.size(); i++) {
		if (isPrime[i] == false) continue;
		else {
			for (int j = 2; i * j < isPrime.size(); j++) 
				isPrime[i*j] = false;
		}
	}
}

void getPartition(int n) {
	int result;
	for (int i = 2; i <= n/2; i++) {		
		if (isPrime[i] && isPrime[n-i]) {
			result = i;
		}
	}
	cout << result << ' ' << n - result << endl;
}


int main() {
	int t;
	cin >> t;

	isPrime.resize(10001, true);
	findPrimeNum();		//먼저 소수들 판별

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		getPartition(n);
	}

	return 0;
}