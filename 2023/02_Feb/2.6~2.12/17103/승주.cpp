#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	vector <int> arr(1000001, 1);
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <= int(sqrt(1000001)); i++) {
		if (arr[i] == 0) continue;
		int j = 2;
		int temp = i * 2;
		while (temp <= 1000000) {
			arr[temp] = 0;
			j++;
			temp = i * j;
		}
	}
	vector <int> goldPart;
	for (int i = 2; i <= int(sqrt(1000001)); i++) {
		if (arr[i] == 1) goldPart.push_back(i);
	}
	int T;
	cin >> T;
	int N;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int firstIdx = 0;
		int secondIdx;
		int cnt = 0;
		while (1) {
			secondIdx = firstIdx;
			int first = goldPart[firstIdx];

			if (first >= N) break;
			int sum;
			while (1) {
				int second = goldPart[secondIdx];
				sum = first + second;
				if (sum == N) { cnt++; break; }
				else if (sum < N) { secondIdx++; }
				else { break; }

			}
			firstIdx++;
		}
		cout << cnt << endl;
	}

}