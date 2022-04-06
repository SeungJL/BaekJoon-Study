#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
	int K, N;
	cin >> K >> N;
	
	vector<int> k(N);
	int t = 0, n = 0;

	for(int i=0; i<K; i++) {
		cin >> k[i];
	}

	t = accumulate(k.begin(), k.end(), 0);
	t /= N; // 다 더해서 N으로 나눈 다음,
	while(1) { // 걔부터 유효한지 확인
		n = 0;
		for(int i=0; i<K; i++) {
			n += k[i]/t;
			if(n == N) {
				cout << t;
				return 0;
			}
		}
		t--;
	}
}