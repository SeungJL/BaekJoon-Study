#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, ans = 0;
	cin >> N >> K;

	if (N <= K) {	//K가 N이상인 경우 상점에서 물병을 사야할 필요가 없다.
		cout << 0;
	}
	else {
		while (true) {
			int cnt = 0;
			int tmp = N;

			while (tmp) {	//갖고 있는 물병을 재분배를 통해 물병의 개수를 최소화한다.
				if (tmp % 2 == 1) {
					cnt++;
				}
				tmp /= 2;
			}

			if (cnt <= K) {	//주어진 조건을 만족하므로 while문을 빠져나온다.
				break;
			}
			N++; //상점에서 물병을 하나 더 산다.
			ans++;	//상점에서 사야하는 물병의 최솟값 1 증가
		}

		cout << ans;
	}

	return 0;
}