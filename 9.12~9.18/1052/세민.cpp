#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, ans = 0;
	cin >> N >> K;

	if (N <= K) {	//K�� N�̻��� ��� �������� ������ ����� �ʿ䰡 ����.
		cout << 0;
	}
	else {
		while (true) {
			int cnt = 0;
			int tmp = N;

			while (tmp) {	//���� �ִ� ������ ��й踦 ���� ������ ������ �ּ�ȭ�Ѵ�.
				if (tmp % 2 == 1) {
					cnt++;
				}
				tmp /= 2;
			}

			if (cnt <= K) {	//�־��� ������ �����ϹǷ� while���� �������´�.
				break;
			}
			N++; //�������� ������ �ϳ� �� ���.
			ans++;	//�������� ����ϴ� ������ �ּڰ� 1 ����
		}

		cout << ans;
	}

	return 0;
}