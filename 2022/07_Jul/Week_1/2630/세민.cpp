#include <iostream>

using namespace std;

int a[128][128];
int wCnt = 0, bCnt = 0;	//�Ͼ�� �������� ����, �Ķ��� �������� ����

void p(int c, int r, int n)
{
	bool flag = true;

	int initColor = a[c][r];	//���� �� ĭ�� ������ ����
	for (int i = c; i < c + n; i++) {
		for (int j = r; j < r + n; j++) {
			if (initColor != a[i][j]) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}

	if (flag) {	//�߶��� ���̰� ��� ���� ���� ���
		if (initColor == 0) wCnt++;	//�߶��� ���̰� ��� ����̶�� �Ͼ�� �������� ���� 1 ����
		else bCnt++;	//�߶��� ���̰� ��� �Ķ����̶�� �Ķ��� �������� ���� 1����
	}
	else {	//�߶��� ���̿� �ٸ� ���� �����ϴ� ��� ��������
		p(c, r, n / 2); //���� ��
		p(c + n / 2, r, n / 2);	//������ ��
		p(c, r + n / 2, n / 2);	//���� �Ʒ�
		p(c + n / 2, r + n / 2, n / 2);	//������ �Ʒ�
	}
}

int main(void)
{
	int N;	//��ü ������ �� ���� ����
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	
	p(0, 0, N);
	cout << wCnt << '\n' << bCnt;

	return 0;
}