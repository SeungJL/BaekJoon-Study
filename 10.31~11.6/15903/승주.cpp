#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long arr[1001];
void shortSort(long long);

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	long long twoSum;
	while (m--) {
		twoSum = arr[0] + arr[1];
		arr[0] = twoSum;
		arr[1] = twoSum;
		shortSort(twoSum);
	}

	long long score = 0;
	for (int i = 0; i < n; i++)
		score += arr[i];
	cout << score;
}

void shortSort(long long twoSum) {

	for (int i = 2; i < n; i++) {
		if (twoSum <= arr[i]) {
			arr[i - 2] = twoSum;
			arr[i - 1] = twoSum;
			break;
		}
		else arr[i - 2] = arr[i];
		if (i == n - 1) {
			arr[i - 1] = twoSum;
			arr[i] = twoSum;
		}
	}

}