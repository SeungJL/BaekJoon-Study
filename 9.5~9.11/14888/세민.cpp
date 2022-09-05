#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;	//수의 개수
int A[11];	//수
int op[4];	//연산자
int MAX = INT_MIN;	//식의 결과의 최댓값
int MIN = INT_MAX;	//식의 결과의 최솟값

void solve(int depth, int val)
{
	if (depth == N) {
		MAX = max(MAX, val);
		MIN = min(MIN, val);
	}

	for (int i = 0; i < 4; ++i) {
		if (op[i] != 0) {	//연산자의 개수가 0이 아니라면
			op[i]--;

			if (i == 0) {	//op[0]은 '+'의 개수
				solve(depth + 1, val + A[depth]);
			}
			else if (i == 1) {	//op[1]은 '-'의 개수
				solve(depth + 1, val - A[depth]);
			}
			else if (i == 2) {	//op[2]은 '*'의 개수
				solve(depth + 1, val * A[depth]);
			}
			else if (i == 3) {	//op[3]은 '/'의 개수
				solve(depth + 1, val / A[depth]);
			}
			op[i]++;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	for (int i = 0; i < 4; ++i) {
		cin >> op[i];
	}
	solve(1, A[0]);
	cout << MAX << '\n' << MIN;
	return 0;
}