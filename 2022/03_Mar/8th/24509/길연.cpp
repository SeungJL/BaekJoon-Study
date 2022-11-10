// 백준 24509번 상품의 주인은

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int n, idx;
int score;

map<int, vector<int>> st;

void Ranking() {

	for (int i = 0; i < 4; i++) {  // 학생들 돌면서 

		int max = 0;
		int max_idx = 0;

		if (!st.empty()){

			for (auto x : st) {

				if (x.second[i] > max) { // 각 과목(i)에서 비교
					max = x.second[i];
					max_idx = x.first;
				}
			}

			cout << max_idx << " ";
			st.erase(max_idx);

		}

	}
	return;
}

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> idx;

		for (int j = 0; j < 4; j++) { 
			cin >> score;
			st[idx].push_back(score);
		}
	}

	Ranking();

	return 0;
}
