#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;


int main() {
	int arr[8];
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}
	int arr2[8];
	copy(arr, arr + 8, arr2);

	sort(arr2, arr2 + 8, greater<>());
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += arr2[i];
	}
	cout << sum << endl;
	int i = 0;
	while (1) {
		if (i == 8) { break; }
		int j = 0;
		while (1) {
			if (j == 5) { break; }
			if (arr[i] == arr2[j]) {
				cout << i + 1 << " ";
				break;
			}
			j++;
		}
		i++;
	}
}

