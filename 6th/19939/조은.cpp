#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int total=0; // 바구니에 넣은 공들의 총 개수
	for (int i = 1; i <= k; i++) {
		// 일단 처음에 k개의 바구나에 각각 1,2,...k개씩 넣는다고 가정
		total += i;
	}

	if(total > n) {
		cout << -1;
		return 0;
	}
	else if((n-total)%k == 0) {
		cout << k-1;
		return 0;
	}
	else {
		cout << k;
		return 0;
	}

	return 0;
}