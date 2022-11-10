#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		unsigned long long price[N];

		for (int j = 0; j < N; j++) {
			cin >> price[j];
		}

		unsigned long long sum = 0;
		unsigned long long max = 0;
		for (int j = N-1; j >= 0; j--) {		
			if (price[j] <= max) 	
				sum += (max - price[j]);
			else
				max = price[j];
		}

		cout << sum << endl;
	}

	return 0;
}