#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N, M, k;
	int visit[10] = {};
	int arr[6];
	int length = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> k;
		visit[k] = 1;
	}
	int i = 0;
	while (1) {
		if (pow(10, i) > N) {
			length = i;
			break;
		}
		i++;
	}
	i = 0;
	int L = length;
	while (length--) {
		arr[i] = N / pow(10, length);
		N -= arr[i] * pow(10, length);
		i++;
	}

	int small;
	int big;

	for (int i = 0; i < L; i++) {
		cout << L;
	}
}