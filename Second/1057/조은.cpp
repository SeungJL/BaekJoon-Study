#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	int N, kim, lim;
	cin >> N >> kim >> lim;

	int round = 1;
	int survivor_n = N;
	while (survivor_n != 1) {
		if ((abs(kim - lim) == 1) && (min(kim, lim) % 2 == 1)) {
			// 둘이 번호가 1차이 나고,
			// 번호 작은애가 홀수, 큰애가 짝수면 => 대결
			break;
		}

		// 다음 라운드 번호 지정, 다음 라운드 생존자 수
		round++;
		kim = (kim + 1) / 2;
		lim = (lim + 1) / 2;
		survivor_n = (survivor_n + 1) / 2;
	}
	
	cout << round;

	return 0;
}
