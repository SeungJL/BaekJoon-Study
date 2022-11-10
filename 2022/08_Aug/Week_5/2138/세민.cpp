#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

constexpr int INF = 987654321;
int N, ans;
string s1, s2, tmp;

void push(int i)
{
	if (i > 0) {
		tmp[i - 1] = (tmp[i - 1] == '0') ? '1' : '0';
	}
	tmp[i] = (tmp[i] == '0') ? '1' : '0';
	if (i < N - 1) {
		tmp[i + 1] = (tmp[i + 1] == '0') ? '1' : '0';
	}
}

void solve(int i, int cnt)
{
	if (i == N - 1) {
		bool flag = true;
		for (int i = 0; i < tmp.length(); ++i) {
			if (tmp[i] != s2[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			ans = min(ans, cnt);
		}
		push(i);
		flag = true;
		for (int i = 0; i < tmp.length(); ++i) {
			if (tmp[i] != s2[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			ans = min(ans, cnt + 1);
		}
		return;
	}
	if (tmp[i - 1] == s2[i - 1]) {
		solve(i + 1, cnt);
	}
	push(i);
	if (tmp[i - 1] == s2[i - 1]) {
		solve(i + 1, cnt + 1);
	}
	push(i);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> s1 >> s2;
	ans = INF;
	tmp = s1;
	solve(1, 0);

	tmp = s1;
	push(0);
	solve(1, 1);
	
	if (ans == INF) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}	