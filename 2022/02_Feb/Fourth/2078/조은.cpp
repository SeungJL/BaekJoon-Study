#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("input.txt", "rt", stdin);
	int A, B;
	cin >> A >> B;
	int L = 0, R = 0;
	while (!(A == 1 && B == 1)) {
		/* A,B �� �ϳ��� 1�� ���� ���� ó�� */
		if (A == 1) {
			R += B - 1;
			break;
		}
		else if (B == 1) {
			L += A - 1;
			break;
		}

		/* �������� ���� ���� �θ�-�ڽ��� �ѹ��� ó�� */
		if (A > B) {
			L += A / B;
			A = A % B;
		}
		else {
			R += B / A;
			B = B % A;
		}
	}

	cout << L << ' ' << R;

	return 0;
}
