// 백준 2822번 점수계산
// 2022년 02월 28일

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
 
	vector < pair<int, int>> score(8); // score, index
	int n = 8;

	for(int i=0; i<n; i++) {
		score[i].second = i +1;
		cin >> score[i].first;
	}
	sort(score.begin(), score.end(), greater<pair<int, int>>()); // score 내림차순

	int sum = 0;
	vector<int> ans;
	for (int i = 0; i < 5; i++) {
		sum += score[i].first;
		ans.push_back(score[i].second);
	}

	cout << sum << endl;

	sort(ans.begin(), ans.end());

	for (int i = 0; i < 5; i++)
		cout << ans[i] << " ";

	cout << endl;

	return 0;
}
