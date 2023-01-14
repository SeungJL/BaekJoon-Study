// https://hio9105.tistory.com/entry/BOJ-9020-%EA%B3%A8%EB%93%9C%EB%B0%94%ED%9D%90%EC%9D%98-%EC%B6%94%EC%B8%A1-math-numbertheory-primalitytest-%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98-%EC%B2%B4

#include <iostream>
#include <vector>

using namespace std;

#define maxN 10000
vector<bool> isPrime(maxN, true);

/* check_prime: maxN 이하의 수의 소수 여부를 구하는 함수 */
void check_prime() {
	for (int i=2; i < maxN; i++) {
		if (!isPrime[i]) continue;
		for (int j=i+i; j < maxN; j += i)
			isPrime[j] = false;
	}
}

/* solve: num의 골드바흐 파티션 중 두 소수의 차이가 가장 작은 파티션을 구하는 함수
 *
 * parametes - num: 골드바흐 파티션을 구하고자 하는 짝수
 * return - 골드바흐 파티션을 구성하는 두 소수 문자열, "소수1 소수2"
 */
string solve(int num) {
	int l = num / 2, r = num / 2;
	while (!(isPrime[l] && isPrime[r])) {
		l--; r++;
	}
	return to_string(l) + " " + to_string(r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	check_prime();

	int TC; cin >> TC;
	while (TC--) {
		int num; cin >> num;
		cout << solve(num) << "\n";
	}
}