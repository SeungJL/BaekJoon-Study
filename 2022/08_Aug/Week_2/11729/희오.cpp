// BOJ 11729

#include <iostream>

using namespace std;

char res[1 << 22];
char *res_p = res;
int cnt = 0;

void hanoi_recur(int n, int src, int dst) {
	if (n <= 0) return;

	hanoi_recur(n-1, src, 6 - (src + dst));

	cnt++;
	*res_p++ = src + '0';
	*res_p++ = ' ';
	*res_p++ = dst + '0';
	*res_p++ = '\n';  

	hanoi_recur(n-1, 6 - (src + dst), dst);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	// init
	int N;
	cin >> N;

	// solve
	hanoi_recur(N, 1, 3);
	*res_p = '\0';
	cout << cnt << "\n" << res;

}