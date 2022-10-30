#include <iostream>

using namespace std;

int N, d, k, c; // N: 접시 수 , d: 초밥의 가짓 수 , k: 연속해서 먹는 접시 수 , c: 쿠폰 번호 

/* count: i부터 k개의 접시와 c번 초밥을 먹었을 때의 초밥 가짓수를 찾는 함수
 * 
 * parameters - belt: 회전초밥 음식점의 벨트 상태
 *            - i: 연속적으로 k개의 초밥을 먹는다고 했을 때, 첫 번쨰 초밥 위치
 * return - i부터 k개의 접시와 c번 초밥을 먹었을 때의 초밥 가짓수
 */
int count(int belt[], int i) {
	bool ch[3001] = {}; // 먹은 초밥 종류를 체크

	int cnt = 0;
	for (int j=0; j<k; j++) {
		if (!ch[belt[(i + j) % N]]) cnt++;
		ch[belt[(i + j) % N]] = true;
	}
	if (!ch[c]) cnt++;

	return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

	/* input */
	cin >> N >> d >> k >> c;

	int belt[N];
	for (int i=0; i<N; i++) cin >> belt[i];

	/* solve */
	int max_cnt = 0; // 먹을 수 있는 초밥 가짓수의 최댓값
	for (int i=0; i<N; i++) {
		int cnt = count(belt, i);
		if (cnt > max_cnt) max_cnt = cnt;
	}

	cout << max_cnt << "\n";
}
