#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>
#include <array>

using namespace std;
string str;
char C[11];
int cnt = 0;
vector <string> V;
int h;

void Permutation(vector <bool> visit, stack <char> s, int k) {
	if (k != -1) {
		visit[k] = 0;
		if (s.empty() != 1 && s.top() == C[k]) { return; }
		s.push(C[k]);

	}
	if (s.size() == str.size()) {
		while (s.empty() != 1) {
			s.pop();
		}
		cnt++;

		return;
	}

	for (int i = 0; i < str.size(); i++) {
		if (C[i] == C[k]) { continue; }
		if (visit[i] == 1) {
			k = i;
			Permutation(visit, s, k); // 이 함수 이전에 작업을 해버리면, 다음 함수에서도 변경 내용이 저장됨
		}
	}
}


int main() {

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		C[i] = str[i];
	}
	sort(C, C + str.size());
	/// str을 사전순으로 정렬했음

	vector <bool> visit(str.size());
	for (int i = 0; i < str.size(); i++) {
		visit[i] = 1;
	}
	//방문했는지를 판단하는 visit

	stack <char> s; // 문자열 입력받는걸 하나씩 넣어줄 스택


	Permutation(visit, s, -1);
	cout << cnt;
}