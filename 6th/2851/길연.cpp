// 백준 2851번 슈퍼 마리오
// 2022년 02월 26일

#include <iostream>

using namespace std;

int main() {

	int mush;
	int sum = 0, before = 0;
	int N = 10;
	int ans = 0;

	for (int i = 0; i < N; i++) {
		cin >> mush;

		before = sum;
		sum = mush + before;

		if (sum == 100) 
			ans = sum;

		if (before < 100 && sum > 100) { // 100을 기준으로 갈라졌을 때
			int a = sum - 100; 
			int b = 100 - before;

			if (a == b || a < b) {  // 차이가 같다면 , sum-100 차이가 더 작다면 큰수인 sum
				ans = sum;
			}
			else if (a > b) // 100-before 차가 더 작다면 before
				ans = before;
		}
	}

	cout << ans << endl;

	return 0;
}
