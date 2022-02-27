#include <iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	//처음에는..
	//1개 차이씩 차등을 주어 담기
	//이 와중에 중간에 숫자가 부족해지면 '나눠 담을 수 없는 경우'가 된다.
	for (int i = K; i >= 1; i--) {	
		N -= i;
		if (N < 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	//이후에는..
	//모든 바구니에 공 한개씩 나눠줄 수 있다면 나눠주기. 모두에게 나눠줄 수 없는 시점이 오면 루프 탈출
	while (N >= K) {
		N -= K;
	}
	//다 끝나고 남았는지 확인. 기본적으로 K - 1개의 차이가 발생하는데, 만약 남아있다면 1을 더하면 된다.
	int result = K - 1;
	if (N > 0) result++;
	cout << result << endl;
	return 0;
}