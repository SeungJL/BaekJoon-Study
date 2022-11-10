// 백준 19939번 박 터뜨리기
// 2022년 02월 28일

#include <iostream>

using namespace std;

int main() {

	int N, k;
	cin >> N >> k;

	int sBall = k * (k + 1) / 2;  // 기본층으로 쌓았을 때(1부터 k까지 연속적)
	int pBall = N - sBall; // 기본층으로 쌓고 남은 공

	if (sBall> N) { // 각 바구니의 공의 개수가 1인게 2개이상 있을 경우
		cout << "-1" << endl;
		return 0;
	}

	int gap;
	if (pBall % k == 0) 
		gap = k - 1;
	else 
		gap = k;

	cout << gap << endl;

	return 0;
}
