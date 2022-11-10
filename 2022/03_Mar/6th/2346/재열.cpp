#include <iostream>
#include <deque>

using namespace std;

int main() {
	int N;
	cin >> N;

	deque<pair<int,int>> d;		// {풍선번호, 적힌숫자} 의 덱

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		d.push_back({i+1, input});
	}

	int nowIndex = d.front().first;
	int move = d.front().second;
	d.pop_front();
	cout << nowIndex << ' ';

	while (!d.empty()) {
		if (move >= 0) {		//move가 양수이면 move-1만큼 앞에서 꺼낸 후 뒤에 넣기 + 앞에서 꺼내기
			for (int i = 0; i < move-1; i++) {
				pair<int,int> temp = d.front();
				d.pop_front();
				d.push_back(temp);
			}
			nowIndex = d.front().first;
			move = d.front().second;
			d.pop_front();
		}
		else {	//move가 음수이면 move-1절댓값만큼 뒤에서 꺼낸 후 앞에 넣기 + 뒤에서 꺼내기
			for (int i = 0; i < -1*move -1; i++) {
				pair<int,int> temp = d.back();
				d.pop_back();
				d.push_front(temp);
			}
			nowIndex = d.back().first;
			move = d.back().second;
			d.pop_back();
		}
		cout << nowIndex << ' ';
	}
	cout << endl;
	return 0;
}