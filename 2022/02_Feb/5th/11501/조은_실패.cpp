#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {/************************************ 실패 (시간초과) ****************************************/
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int T;
	cin >> T;

	int N;
	while (T--) {
		cin >> N;
		vector<int> price(N);
		vector<int> index; // 주가가 오르거나 내리는 지점의 index를 저장
		index.push_back(0); // 
		for (int i = 0; i < N; i++) {
			cin >> price[i];
			if (i > 0) {
				if (price[i - 1] < price[i])index.push_back(i); // 주가가 오르는 index를 그냥그대로 저장
				else if (price[i - 1] > price[i]) index.push_back(-i); // 주가가 내리는 index를 음수로 바꿔서 저장
			}
		}
		for (int i = 1; i < index.size() - 1; i++) {
			// 주가의 등락이 역전될 때만 남기고 다 삭제
			if ((index[i] < 0 && index[i + 1] < 0) || (index[i] > 0 && index[i + 1] > 0)) index.erase(index.begin() + i);
		}

		int buy = 0, hold = 0; // 총 매수량, 순이익을 포함한 총 보유량
		for (int i = 0; i < index.size() - 1; i++) {
			if (index[i + 1] < 0) continue;
			else {
				int t_buy = 0, t_hold = 0; // 임시변수
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
* 만약 5일 동안의 주가가 '1 1 3 1 2' 라면,
* index 벡터엔 값 '2 -3 4' 가 들어감
*/