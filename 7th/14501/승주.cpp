#include <iostream>

using namespace std;
int N;
int T[15];
int P[15];

int cnt(int day, int sum) {
	int count2 = 0;

	if (day == N) {
		return sum;
	}
	if (day + T[day] > N) {
		return cnt(day + 1, sum);
	}
	if (T[day] == 1) {
		return cnt(day + 1, sum + P[day]);
	}
	if (T[day] > 1) {
		if (day + T[day] <= N && cnt(day + 1, sum) < cnt(day + T[day], sum + P[day])) {
			return cnt(day + T[day], sum + P[day]);
		}
		else {
			return cnt(day + 1, sum);
		}
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	cout << cnt(0, 0);
}