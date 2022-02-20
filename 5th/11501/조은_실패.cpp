#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {/************************************ ���� (�ð��ʰ�) ****************************************/
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int T;
	cin >> T;

	int N;
	while (T--) {
		cin >> N;
		vector<int> price(N);
		vector<int> index; // �ְ��� �����ų� ������ ������ index�� ����
		index.push_back(0); // 
		for (int i = 0; i < N; i++) {
			cin >> price[i];
			if (i > 0) {
				if (price[i - 1] < price[i])index.push_back(i); // �ְ��� ������ index�� �׳ɱ״�� ����
				else if (price[i - 1] > price[i]) index.push_back(-i); // �ְ��� ������ index�� ������ �ٲ㼭 ����
			}
		}
		for (int i = 1; i < index.size() - 1; i++) {
			// �ְ��� ����� ������ ���� ����� �� ����
			if ((index[i] < 0 && index[i + 1] < 0) || (index[i] > 0 && index[i + 1] > 0)) index.erase(index.begin() + i);
		}

		int buy = 0, hold = 0; // �� �ż���, �������� ������ �� ������
		for (int i = 0; i < index.size() - 1; i++) {
			if (index[i + 1] < 0) continue;
			else {
				int t_buy = 0, t_hold = 0; // �ӽú���
				for (int j = abs(index[i]); j < index[i + 1]; j++) {
					t_buy += price[j];
					t_hold = (t_hold + price[j]) * price[j + 1] / price[j];
				}
				buy += t_buy;
				hold += t_hold;
			}
		}
		cout << hold - buy << '\n';
	}

	return 0;
}

/*
* ���� 5�� ������ �ְ��� '1 1 3 1 2' ���,
* index ���Ϳ� �� '2 -3 4' �� ��
*/