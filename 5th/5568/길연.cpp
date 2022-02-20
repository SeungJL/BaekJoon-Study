// 백준 5568번 카드 놓기

#include <iostream>
#include <vector>
#include <unordered_set>
#include<string>

using namespace std;
vector<int> card; // n개 숫자 컨테이너
unordered_set<string> numSet; // k개 만큼 선택해서 만든 숫자열 저장 
bool check[11] = { 0 };
int n, k;

// k개 만큼 뽑아서 정수 만듦 -> 중복 제거해야해서 set사용
void makeNum(int cnt, string num) {
	if (cnt == k) { // k개 만큼 다 선택했으면
		numSet.insert(num);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i] == 0) {
			check[i] = 1; // 현재 선택한 index 방문체크
			makeNum(cnt + 1, num + to_string(card[i]));
			check[i] = 0;
		}
	}
		
}

int main() {

	cin >> n >> k;
	card.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> card[i];

	makeNum(0, "");
	cout << numSet.size();

	return 0;
}
