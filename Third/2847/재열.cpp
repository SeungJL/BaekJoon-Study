#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int scores[n];

	for (int i = 0; i < n; i++) {
		cin >> scores[i];
	}

	int count = 0;
	for (int i = n-1; i >= 1; i--) {		//가장 마지막 원소부터 이전 원소와 비교하며 탐색
		while (scores[i-1] >= scores[i]) {		//이전 원소가 현재 원소보다 작아질 때까지 1씩 줄인다.
			scores[i-1]--;
			count++;
		}
	}
	
	cout << count << endl;

	return 0;
}