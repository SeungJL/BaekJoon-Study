#include <iostream>
#include <algorithm>

using namespace std;

int p[1001];

int main(void)
{
	int N, L, cnt = 1;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}

	sort(p, p + N); // ���� ���� ���� ��ġ ������������ ����
	
	int tmp = p[0]; // ���� ó�� ���� ��

	for (int i = 1; i < N; i++) {
		if (tmp + L < p[i] + 1) {	//�������� ���� ���� �� �ִ� ������ ����� �������� �� �߰�
			cnt++;
			tmp = p[i];	// ���� ���� ���� �ٽ� ����
		}
	}

	cout << cnt;

	return 0;
}