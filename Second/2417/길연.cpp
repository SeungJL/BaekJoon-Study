// 백준 2417번 정수 제곱근
// 2022년 01월 25일 

#include <iostream>
#include <cmath>

using namespace std;

int main() {

	long long num;
	cin >> num;

	long long ans;
	ans = sqrt(num);

	if (ans * ans < num) {
		ans += 1;
	}

	cout << ans;

	return 0;
}
