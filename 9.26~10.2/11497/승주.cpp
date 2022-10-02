#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T, N;
	int arr[10001];
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) cin >> arr[j];
		sort(arr, arr + N);
		int Max = 0;
		int temp;
		for (int j = 0; j < N - 2; j++) {
			temp = arr[j + 2] - arr[j]; //정렬했을때 두 칸의 거리가 가장 큰 것을 찾으면 된다.
			if (temp > Max) Max = temp;
		}
		cout << Max << '\n';
	}
}

// 희오 to 승주
