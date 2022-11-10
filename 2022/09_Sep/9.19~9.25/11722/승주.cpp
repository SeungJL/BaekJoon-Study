#include <iostream>

using namespace std;

int main() {
	int N;
	int arr[1001];
	int DP[1001] = {};
	int Max = 0;
	cin >> N;
	if (N == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		if (i == N - 1) { DP[N - 1] = 1; continue; }
		int Max_Temp = 0;
		for (int j = i + 1; j < N; j++) {
			if (arr[i] > arr[j] && DP[j] > Max_Temp) {
				Max_Temp = DP[j];
			}
		}
		DP[i] = Max_Temp + 1;
		if (DP[i] > Max) {
			Max = DP[i];
		}
	}
	cout << Max;
}