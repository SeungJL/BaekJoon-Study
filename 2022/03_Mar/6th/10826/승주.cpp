#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>

using namespace std;




int main() {
	iostream::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr1[100001] = {};
	int arr2[100001] = {};

	arr1[0] = 0;
	arr2[0] = 1;
	int n;
	cin >> n;
	n--;
	int cnt = 1;
	int c = 0;
	while (n--) {
		for (int i = 0; i < cnt; i++) {
			if (arr1[i] + arr2[i] + c < 10) {
				int temp = arr1[i] + arr2[i] + c;
				arr1[i] = arr2[i];
				arr2[i] = temp;
				c = 0;
			}
			else {
				int temp = arr1[i] + arr2[i] + c - 10;
				arr1[i] = arr2[i];
				arr2[i] = temp;
				c = 1;
			}
		}
		if (c == 1) {
			arr2[cnt] = 1;
			cnt++;
			c = 0;
		}

	}
	if (c == 1) { cnt--; }
	for (int j = cnt - 1; j >= 0; j--) {
		cout << arr2[j];
	}
}



