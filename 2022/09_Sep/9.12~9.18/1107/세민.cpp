#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool b[10]; //버튼의 정상 작동 여부를 저장, if True => broken

int solve(int n)
{
	if (n == 0) {	//고장난 버튼이 없는 경우 예외 처리
		if (b[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int len = 0;
	while (n > 0) {
		if (b[n % 10]) return 0;
		n /= 10;
		len++;
	}

	return len;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int tmp;
		cin >> tmp;
		b[tmp] = true;
	}

	int ans = abs(N - 100);
	for (int i = 0; i <= 1'000'000; ++i) {	//0부터 1'000'000 채널을 모두 돌면서 버튼을 가장 적게 울러 이동할 수 있는 채널을 찾는다.
		int c = i;	
		int l = solve(c);	//c로 숫자 버튼을 이용해서 이동 가능한지, 몇 번 버튼을 눌러야하는지 구한다.
		if (l > 0) {	
			int press = abs(c - N);
			if (ans > l + press) ans = l + press;
		}
	}

	cout << ans;


	return 0;
}