// https://hio9105.tistory.com/entry/BOJ-2505-%EB%96%A1-%EB%A8%B9%EB%8A%94-%ED%98%B8%EB%9E%91%EC%9D%B4-bruteforcing-dp-math

#include <iostream>
using namespace std;

string solve(int D, int K) {
	int fibo[D];
	fibo[0] = 0; fibo[1] = 1;
	for (int i=2; i<=D; i++) fibo[i] = fibo[i-2] + fibo[i-1];

	int a = 1, b = 1;
	while (1) {
		b = a;
		while (1) {
			int tmp = (fibo[D-2] * a) + (fibo[D-1] * b);
			if (tmp == K) {
				return to_string(a) + "\n" + to_string(b);
			}
			else if (tmp > K) break;
			else b++;
		}
		a++;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	int D, K;
	cin >> D >> K;
	string ans = solve(D, K);
	cout << ans;
	
}