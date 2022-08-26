#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

struct food {
	int p, f, s, v, c;
};

int N;	//3<=N<=15
int mp, mf, ms, mv;
int cost = INT_MAX;
int _L;
vector<food> vec(16);
int tmp[16], ans[16];
bool visited[16];

void calculate(int L)
{
	int tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0, tmp5 = 0;
	for (int i = 1; i <= L; ++i) {
		tmp1 += vec[tmp[i]].p;
		tmp2 += vec[tmp[i]].f;
		tmp3 += vec[tmp[i]].s;
		tmp4 += vec[tmp[i]].v;
		tmp5 += vec[tmp[i]].c;
	}
	if (tmp1 >= mp && tmp2 >= mf && tmp3 >= ms && tmp4 >= mv && cost > tmp5) {
		cost = tmp5;
		for (int i = 1; i <= L; ++i) {
			ans[i] = tmp[i];
		}
		_L = L;
	}

	return;
}

void solve(int cnt, int order)
{
	for (int i = cnt; i <= N; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			tmp[order] = i;
			calculate(order);
			solve(tmp[order], order + 1);
			visited[i] = false;
		}
	}
	return;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("input.txt", "r", stdin);
	cin >> N;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 1; i <= N; ++i) {
		cin >> vec[i].p >> vec[i].f >> vec[i].s >> vec[i].v >> vec[i].c;
	}

	solve(1, 1);
	if (_L > 0) {
		cout << cost << '\n';
		for (int i = 1; i <= _L; ++i) {
			cout << ans[i] << " ";
		}
		cout << '\n';
	}
	else {
		cout << "-1";
	}

	return 0;
}