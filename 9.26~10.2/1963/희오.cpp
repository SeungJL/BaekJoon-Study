// 1963

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define num first 
#define cnt second 

int isPrime[10000] = {}; // i가 소수인지 정보를 담고 있는 배열, 중복확인을 방지하기 위함

/* check_prime: 소수인지 판단하는 함수 
 *
 * parameter - n: 소수인지 판단하고자 하는 숫자
 * return: 소수이면 true, 소수가 아니면 false
 */
bool check_prime(int n) {
	if (isPrime[n]) 
		return (isPrime[n] > 0) ? true : false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			isPrime[n] = -1;
			return false;
		}
	}
	isPrime[n] = 1;
	return true;
}

/* find_next_prime: 현재 숫자에서 한 자릿수만을 바꿔 만들 수 있는 소수를 찾는 함수
 *                  한 자릿수를 0~9로 하나씩 바꿔 check_prime()을 이용해 소수인지 확인, 이 동작을 네 개의 자릿수에 대해 반복
 *
 * parameter - org: 바꾸기 전 소수 비밀번호
 *           - next: org에서 바꿀 수 있는 소수 비밀번호를 저장할 배열
 *           - ch: 이미 바꾼 적 있는 비밀번호인지 확인하기 위해 체크 배열 
 */
void find_next_prime(int org, vector<int> &next, bool ch[]) {
	int new_num;
	int tmp = org;
	for (int d=1; d<=1000; d *= 10) {
		new_num = org - (tmp % 10) * d; // 바꾸고자 하는 자릿수를 0으로 초기화 
		tmp /= 10;
		for (int i=0; i<10; i++) {
			if ((1000 <= new_num && new_num < 10000) && !ch[new_num]) { 
				if (check_prime(new_num)) 
					next.push_back(new_num);
			}
			new_num += d; // 1, 10, 100, 1000씩 더하면서 바꾸고자 하는 자릿수를 0~9로 바꿈
		}
	}
}

/* solve: 문제를 푸는 함수
 *        find_next_prime()을 이용해 현재 숫자에서 바꿀 수 있는 소수 숫자를 찾음
 *        bfs를 이용해 구현, 위 동작을 최종적으로 이동하고자 하는 비밀번호가 나올 때까지 반복
 *
 * parameter - from: 현재 소수 비밀번호
 *           - to: 바꿀 소수 비밀번호
 * return: 정답, from에서 to로 바꾸는데 필요한 횟수
 *         from에서 to로 바꿀 수 없는 경우 -1을 리턴
 */
int solve(int from, int to) {
	queue<pair<int, int>> Q;
	bool ch[10000] = {};

	Q.push(make_pair(from, 0));
	ch[from] = true;

	if (from == to) return 0; // 현재 비밀번호와 바꾸고자 하는 비밀번호가 동일한 경우

	while (!Q.empty()) {
		int num = Q.front().num; // 소수 비밀번호
		int cnt = Q.front().cnt; // to에서 num까지 바꾸는 데에 필요한 횟수
		Q.pop();

		vector<int> next_nums;  // 현재 비밀번호 num에서 바꿀 수 있는 소수 비밀번호 집합
		find_next_prime(num, next_nums, ch);
		for (auto next : next_nums) {
			if (next == to) return (cnt + 1);
			if (ch[next]) continue;
			Q.push(make_pair(next, cnt + 1));
			ch[next] = true;
		}
	}
	return (-1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int TC;
	cin >> TC;
	while (TC--) {
		/* input */
		int from, to;
		cin >> from >> to;

		/* solve */
		int res = solve(from, to);
		(res >= 0) ? cout << res << "\n" : cout << "Impossible\n";
	}

}