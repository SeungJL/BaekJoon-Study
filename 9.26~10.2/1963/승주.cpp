#include <iostream>
#include <string>

using namespace std;

string Start, End;
int visit[4] = {};
int arr[10000] = {};
int Min = 100;

void DFS(string Num, int beforeNum, int cnt) {

	if (cnt >= Min)
		return;
	if (Num == End) {
		Min = cnt;
		return;
	}
	for (int i = 0; i < 4; i++) { // 현재 탐색하고 있는 index
		if (beforeNum != i && visit[i] < 2) {
			visit[i]++; // 일정 횟수까지는 재방문 가능
			for (int j = 0; j <= 9; j++) {
				string temp = Num;
				temp[i] = j + '0'; //탐색하고 있는 index의 숫자를 모든 경우에 대해 바꾸어 본다.
				if (arr[stoi(temp)] == 0)
					continue;
				if (Num[i] != temp[i]) { cnt++; } //동일한 경우에는 카운트가 증가하지 않는다.
				arr[stoi(temp)] = 0; // 재방문이 가능하다보니, 중복되는 숫자들을 탐색하게 된다. 이를 방지하기 위해 0으로.
				DFS(temp, i, cnt); // 재귀 호출
				arr[stoi(temp)] = 1;
				if (Num[i] != temp[i]) { cnt--; }
			}
			visit[i]--;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	for (int i = 1000; i < 10000; i++)
		arr[i] = i;

	for (int i = 2; i < 100; i++) {
		for (int j = 1000; j < 10000; j++) {
			if (arr[j] != 0 && j % i == 0)
				arr[j] = 0;
		}
	} // 에라토스테네스의 체
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> Start >> End;
		Min = 10000;
		DFS(Start, -1, 0);
		cout << Min << '\n';
	}