#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int r, c, k;
int R_new, C_new;	//�ٲ�� ��� ���� ũ��
int A[101][101];	
int A_T[101][101];	
int num_cnt[101];	//���� Ƚ�� ����� �迭

void transpose() {	//C ������ �ϱ� ���� ����� ��� ���� �ٲ۴�. (��ġ���)
	for (int i = 1; i <= R_new; i++) {
		for (int j = 1; j <= C_new; j++) {
			A_T[j][i] = A[i][j];
		}
	}
}

void reset() {
	for (int i = 1; i <= R_new; i++) {
		for (int j = 1; j <= C_new; j++) {
			A[i][j] = A_T[j][i];
		}
	}
}

int Sort(int(&S)[101][101], int R, int C) {
	int l = 0;
	vector<int> Size;
	for (int i = 1; i <= R; i++) {
		vector<pair<int, int>> v;
		memset(num_cnt, 0, sizeof(num_cnt));
		for (int j = 1; j <= C; j++) num_cnt[S[i][j]]++;
		for (int j = 1; j < 101; j++) {
			if (num_cnt[j] == 0) continue;	//���� Ƚ���� 0�� ��� ����
			v.push_back(make_pair(num_cnt[j], j));	//���� Ƚ���� ���ڸ� vector�� ����
		}
		sort(v.begin(), v.end());	//����
		for (int j = 1; j <= C; j++) S[i][j] = 0; //���� Ŀ�� ������ 0���� ä���.
		int idx = 1;	//�迭�� �ε����� 1���� ����
		for (int j = 0; j < v.size(); j++) {
			S[i][idx++] = v[j].second;	//�迭�� ���ĵ� ������� ���ڸ� ����
			S[i][idx++] = v[j].first;	//�迭�� ���ĵ� ������� ���� Ƚ���� ����
		}
		idx--;
		Size.push_back(idx);
	}
	sort(Size.begin(), Size.end());
	l = Size.back();

	return l; //�ִ� ��(���� ũ��)�� return
}
int main(void)
{
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> A[i][j];
		}
	}
	R_new = 3, C_new = 3;	//�ʱ� ��� ���� ũ��� ��� 3

	int T = 0;	//�ð�
	while (true) {
		if (T > 100) {	//100�ʰ� ������ T�� -1 �Ҵ� �� while���� �������´�.
			T = -1;
			break;
		}
		if (A[r][c] == k) {	//A[r][c] = k ��� T ��� �� while���� �������´�.
			cout << T;
			break;
		}
		if (C_new > R_new) {	//C ����
			transpose();
			R_new = Sort(A_T, C_new, R_new);
			reset();
		}
		else {	//R ����
			C_new = Sort(A, R_new, C_new);
		}
		T++;	//increment T by 1
	}

	if (T == -1) {
		cout << -1;
	}

	return 0;
}