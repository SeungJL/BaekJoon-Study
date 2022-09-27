#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[9];
int N;
int Max = 0;

void cal() {
	int sum = 0;
	for (int i = 0; i < N - 1; i++) {
		sum += abs(arr[i] - arr[i + 1]);
	}
	if (sum > Max)
		Max = sum;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	do {
		cal();
	} while (next_permutation(arr, arr + N));
	cout << Max;
}