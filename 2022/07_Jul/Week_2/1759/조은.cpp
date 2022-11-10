/* BOJ #1759. 실패*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int L, C;
vector<char> pw;
vector<char> chars;
bool isused[16];

const set<char> vowels = { 'a','e','i','o','u' };

/* 모음1 자음2 조건 체크 */
bool check() {
	int v_cnt = 0;  // 모음 개수
	int c_cnt = 0;  // 자음 개수
	
	for(int i=0; i<L; i++) {
		if (vowels.count(pw[i])) v_cnt++;
		else c_cnt++;
	}

	if ((v_cnt >= 1) && (c_cnt >= 2)) return true;
	return false;
}

void dfs(int cnt) {
	if (cnt == L) {  // 종료조건
		if (check()) {
			for (auto it : pw) {
				cout << it;
			}
			cout << '\n';
		}
		return;
	}

	for(int i=cnt; i<C; i++) {  // 조합
		if (!isused[i]) {
			pw.push_back(chars[i]);
			isused[i] = true;
			dfs(i+1);
			pw.pop_back();
			isused[i] = false;
		}
	}

	return;
}

int main() {
	cin >> L >> C;

	for(int i=0; i<C; i++) {
		char n;
		cin >> n;
		chars.push_back(n);
	}

	sort(chars.begin(), chars.end());

	dfs(0);
	
	return 0;
}