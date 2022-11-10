#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool b[10]; //��ư�� ���� �۵� ���θ� ����, if True => broken

int solve(int n)
{
	if (n == 0) {	//���峭 ��ư�� ���� ��� ���� ó��
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
	for (int i = 0; i <= 1'000'000; ++i) {	//0���� 1'000'000 ä���� ��� ���鼭 ��ư�� ���� ���� �﷯ �̵��� �� �ִ� ä���� ã�´�.
		int c = i;	
		int l = solve(c);	//c�� ���� ��ư�� �̿��ؼ� �̵� ��������, �� �� ��ư�� �������ϴ��� ���Ѵ�.
		if (l > 0) {	
			int press = abs(c - N);
			if (ans > l + press) ans = l + press;
		}
	}

	cout << ans;


	return 0;
}