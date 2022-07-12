#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector <char> Left;
vector <char> Right;
vector <string> V;
int L;

void DFS_right(string str, int pos, int cnt, int right_cnt) {
	if (cnt == right_cnt) {
		sort(str.begin(), str.end());
		V.push_back(str);
		return;
	}
	if (pos >= Right.size()) {
		return;
	}

	DFS_right(str + Right[pos], pos + 1, cnt + 1, right_cnt);
	DFS_right(str, pos + 1, cnt, right_cnt);
}

void DFS_left(string str, int pos, int cnt, int left_cnt) {
	if (cnt == left_cnt) {
		return DFS_right(str, 0, 0, L - left_cnt);
	}
	if (pos >= Left.size()) {
		return;
	}

	DFS_left(str + Left[pos], pos + 1, cnt + 1, left_cnt);
	DFS_left(str, pos + 1, cnt, left_cnt);
}



int main() {
	int C;
	char c;
	string str;

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> c;
		if (c == 'i' || c == 'a' || c == 'e' || c == 'o' || c == 'u') {
			Right.push_back(c); // 모음
		}
		else {
			Left.push_back(c); // 자음
		}
	}
	for (int i = 1; i <= Right.size(); i++) {
		int j = L - i; // i는 사용 할 모음의 개수, j는 사용할 자음의 개수
		if (j < 2 || j>Left.size()) { continue; }
		DFS_left("", 0, 0, j);
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++) {
		cout << V[i] << endl;
	}

}