#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[10001] = { 0,1, };

	int visit[10001] = { 0,1, };
	int sum = 1;
	cout << 1 << " ";
	for (int i = 2; i <= N; i++) {
		int k = 1;

		while (1) {
			if (visit[k] == 0 && (sum + k) % i == 0) { break; }
			else { k += 2; }
		}
		for (int j = 2; j < i; j++) {

			if (visit[k] == 0 && k % j == arr[i - j] % j) {
				continue;
			}
			else {
				k += 2;
				j--;
			}
		}
		cout << k << " ";
		sum += k;
		arr[i] = k;
		visit[k] = 1;
	}

}
