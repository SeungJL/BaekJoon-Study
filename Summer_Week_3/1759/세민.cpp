#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int L, C;
char ch;
vector <char> v;
vector <char> ans;

bool check()
{
	int num = 0;
	for (int i = 0; i < L; i++) {
		if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
			num++;
	}
	if (num >= 1 && L - num >= 2)
		return true;
	return false;
}

void dfs(int cnt)
{
	if (ans.size() == L) {
		if (check()) {
			for (int i = 0; i < L; i++) {
				cout << ans[i];
			}
			cout << '\n';
		}
		return;
	}
	for (int i = cnt; i < C; i++) {
		ans.push_back(v[i]);
		dfs(i + 1);
		ans.pop_back();
	}
	return;
	
}

int main(void)
{
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> ch;
		v.push_back(ch);
	}

	sort(v.begin(), v.end());

	dfs(0);
	
	return 0;
}