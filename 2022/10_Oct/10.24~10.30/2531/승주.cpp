#include <iostream>

using namespace std;

int main() {
	int N, d, k, c;
	int visit[3001] = {};
	int cnt = 0;
	int arr[30001];
	int Max = 0;
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < k; i++) {
		visit[arr[i]]++;
		if (arr[i] != c && visit[arr[i]] == 1) {
			cnt++;
		}
	}
	int second;
	for (int i = 0; i < N; i++) {
		visit[arr[i]]--;
		if (visit[arr[i]] == 0 && arr[i] != c) cnt--;
		if (i + k < N) second = i + k;
		else second = i + k - N;
		visit[arr[second]]++;
		if (visit[arr[second]] == 1 && arr[second] != c) { cnt++; }
		if (cnt > Max) { Max = cnt; }
	}
	cout << Max + 1;
}