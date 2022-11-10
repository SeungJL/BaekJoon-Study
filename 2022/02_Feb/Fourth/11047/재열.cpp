#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> coins(n);

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	int count = 0;
	int sum = 0;
	for (int i = n-1; i >= 0; i--) {		//가장 큰 단위의 동전부터 작은 단위의 동전까지 시행.
		while (sum < k) {
			sum += coins[i];
			count++;
		}
		if (sum > k) {		//탈출했을때 초과된 케이스 있으므로 그럴 경우 방금 추가한 코인 꺼낸다.
			sum -= coins[i];
			count--;
		}
		if (sum == k) {		//추가한 동전의 총 합이 목표 금액과 같으면 for루프 탈출.
			break;
		}
	}

	cout << count << endl;

	return 0;
}