// 1188
// https://hio9105.tistory.com/entry/BOJ-1188-%EC%9D%8C%EC%8B%9D-%ED%8F%89%EB%A1%A0%EA%B0%80-euclidean-math-numbertheory

#include <iostream>

using namespace std;

/* get_gcd: parameter로 주어지는 두 수 a, b의 최대공약수를 구하는 함수 (a > b) */
int get_gcd(int a, int b) {
	int r = a % b;
	if (r == 0) return b;
	return get_gcd(b, r);
}

/* get_lcm: parameter로 주어지는 두 수 a, b의 최소공배수를 구하는 함수 */
int get_lcm(int a, int b) {
	int gcd = (a >= b) ? get_gcd(a, b) : get_gcd(b, a);
	return a * b / gcd;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	/* input */
	int N, M;
	cin >> N >> M;

	/* solve */
	int ans = (M - 1) - (N * M / get_lcm(N, M) - 1);
	cout << ans << "\n";

}