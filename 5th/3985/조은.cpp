#include <iostream>
#include <algorithm>
using namespace std;

int cake[1001]; // 케이크 조각 별로 방청객 번호
int cnt[1001]; // 방청객 번호 별로 실제 받게되는 케이크 수 

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int L, N;
	cin >> L >> N;
	int st, en, _max=-1, _max_index=-1;
	for (int i = 1; i <= N; i++) {
		cin >> st >> en;
		for (int j = st; j <= en; j++) {
			if (cake[j] == 0) { // 케이크 배열이 비어있는 경우에만 갱신
				cake[j] = i;
			}
		}

		if (en-st+1 > _max) { // _max를 초과 시 _max_index 갱신
			_max = en-st+1;
			_max_index = i;
		}
	}
	cout << _max_index << '\n';


	for (int i = 1; i <= L; i++) {
		if (cake[i] > 0) cnt[cake[i]]++; // 방청객 별로 실제 받게되는 케이크 수 카운트
	}

	_max=-1, _max_index=-1;
	for (int i = 1; i <= N; i++) { // _max를 초과 시 _max_index 갱신
		if (cnt[i] > _max) {
			_max = cnt[i];
			_max_index = i;
		}
	}
	cout << _max_index << '\n';

	return 0;
}