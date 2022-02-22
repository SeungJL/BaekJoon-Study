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
			Permutation(visit, s, k); // �� �Լ� ������ �۾��� �ع�����, ���� �Լ������� ���� ������ �����
		}
	}
}


int main() {

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		C[i] = str[i];
	}
	sort(C, C + str.size());
	/// str�� ���������� ��������

	vector <bool> visit(str.size());
	for (int i = 0; i < str.size(); i++) {
		visit[i] = 1;
	}
	//�湮�ߴ����� �Ǵ��ϴ� visit

	stack <char> s; // ���ڿ� �Է¹޴°� �ϳ��� �־��� ����


	Permutation(visit, s, -1);
	cout << cnt;
}