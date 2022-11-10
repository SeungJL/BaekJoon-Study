#include <iostream>>

using namespace std;

int main() {

	int N, C, W;
	int arr[51];
	int Min = 0;
	long long SumMax = 0;
	long long sum;
	cin >> N >> C >> W;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] > Min) {
			Min = arr[i];
		}
	}

	do {
		if (Min == 0) { break; }
		sum = 0;
		for (int i = 0; i < N; i++) {
			int CCount = 0;
			if (arr[i] < Min) {
				continue;
			}
			if (arr[i] % Min == 0) {
				CCount = arr[i] / Min - 1;
			}
			else {
				CCount = arr[i] / Min;
			}
			if (W * Min * (arr[i] / Min) - C * CCount > 0) {
				sum += (long long)W * (long long)Min * (long long)(arr[i] / Min) - (long long)C * (long long)CCount;
			}
		}
		if (sum > SumMax) {
			SumMax = sum;
		}
	} while (Min--);
	cout << SumMax;
}