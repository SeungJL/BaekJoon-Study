// 2096

#include <iostream>

using namespace std;

#define S first
#define L second 

/* get_min_n_max:
 *
 * parameter - prev: 이전 줄까지의 최고, 최소 점수 데이터, dp이용, prev[i] = 이전 줄의 i번째를 선택했을 때의 최고/최소 점수
 *           - cur: 현재 줄의 3개의 숫자 중 포함하고자 하는 숫자의 인덱스
 *           - min_sum: input[cur]을 포함했을 때의 최소 점수
 *           - max_sum: input[cur]을 포함했을 때의 최고 점수
 */
void get_min_n_max(pair<int, int> prev[], int cur, int &min_sum, int &max_sum) {
	min_sum = 1000000, max_sum = -1;
	for (int i = cur-1; i <= cur+1; i++) {
		if (i < 0 || i >= 3) continue;
		if (prev[i].S < min_sum) min_sum = prev[i].S;
		if (prev[i].L > max_sum) max_sum = prev[i].L;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	/* input */
	int N;
	cin >> N;
	pair<int, int> prev[3];
	pair<int, int> input[3];

	/* solve */
	int tmp;
	for (int i=0; i<3; i++) {
		cin >> tmp;
		prev[i] = make_pair(tmp, tmp);
	}

	int min_sum, max_sum;
	for (int depth=1; depth<N; depth++) {
		for (int i=0; i<3; i++) {
			get_min_n_max(prev, i, min_sum, max_sum);
			cin >> tmp;
			input[i] = make_pair(tmp + min_sum, tmp + max_sum);
		}
		
		for (int i=0; i<3; i++) {
			prev[i].S = input[i].S;
			prev[i].L = input[i].L;
		}
	}

	get_min_n_max(prev, 1, min_sum, max_sum);
	cout << max_sum << " " << min_sum << "\n";

}