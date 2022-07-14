#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int S[10001] = { 0, };
long long low, mid, high;

int main(void)
{
	int K, N;
	cin >> K >> N;
	
	for (int i = 0; i < K; i++) {
		cin >> S[i];
	}
	sort(S, S + K);
	low = 1, high = S[K - 1];
	int ans = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 0; i < K; i++)
			cnt += S[i] / mid;

		if (cnt >= N) {
			low = mid + 1;
			if (ans < mid)
				ans = mid;
		}
		else {
			high = mid - 1;
		}
	}

	cout << ans;
	return 0;
}