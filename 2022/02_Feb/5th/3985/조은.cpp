#include <iostream>
#include <algorithm>
using namespace std;

int cake[1001]; // ����ũ ���� ���� ��û�� ��ȣ
int cnt[1001]; // ��û�� ��ȣ ���� ���� �ްԵǴ� ����ũ �� 

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int L, N;
	cin >> L >> N;
	int st, en, _max=-1, _max_index=-1;
	for (int i = 1; i <= N; i++) {
		cin >> st >> en;
		for (int j = st; j <= en; j++) {
			if (cake[j] == 0) { // ����ũ �迭�� ����ִ� ��쿡�� ����
				cake[j] = i;
			}
		}

		if (en-st+1 > _max) { // _max�� �ʰ� �� _max_index ����
			_max = en-st+1;
			_max_index = i;
		}
	}
	cout << _max_index << '\n';


	for (int i = 1; i <= L; i++) {
		if (cake[i] > 0) cnt[cake[i]]++; // ��û�� ���� ���� �ްԵǴ� ����ũ �� ī��Ʈ
	}

	_max=-1, _max_index=-1;
	for (int i = 1; i <= N; i++) { // _max�� �ʰ� �� _max_index ����
		if (cnt[i] > _max) {
			_max = cnt[i];
			_max_index = i;
		}
	}
	cout << _max_index << '\n';

	return 0;
}