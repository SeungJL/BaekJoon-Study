#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int S[21][21]; // 1����~N����
bool check[21]; // ��ŸƮ���� true, ��ũ���� false
int gap = 2100000000;

/* N/2 ���� �� �ɷ�ġ ��� */
void func(int cnt, int cur) { // ���� ��ŸƮ������ cur�� ������� cnt�� �� ����

	if (cnt == N / 2) { // n/2���� ��� ���� �� ®����
		int start = 0, link = 0;
		for (int i = 1; i <= N; i++) {
			if (check[i]) { // true��, �� ��ŸƮ�� �ɷ�ġ ���
				for (int j = 1; j <= N; j++) {
					if (check[j]) {
						start += S[i][j];
					}
				}
			}
			else { // false��, �� ��ũ�� �ɷ�ġ ���
				for (int j = 1; j <= N; j++) {
					if (!check[j]) {
						link += S[i][j];
					}
				}
			}
		}

		gap = min(gap, abs(start - link));
		return;
	}

	for (int i = cur + 1; i <= N; i++) { // �� ����
		check[i] = true;
		func(cnt + 1, i); // ���� ����� ���� �� �ܰ� �� �� (dfs)
		check[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S[i][j];
		}
	} // �Է�

	func(0, 1);

	cout << gap;

	return 0;
}