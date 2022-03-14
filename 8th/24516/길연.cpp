// 백준 24516번 잘 알려진 수열 구하기

#include <iostream>
using namespace std;

int main(void) {
	int k;
	cin >> k;

	for (int i = 0; i < k; i++)   // 1 3 5 7 ``  or 2 4 6 ```
		cout << 2 * i + 1 << ' ';

	return 0;
}
