#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {

	int Min = 100;
	int x;
	int flag = 0;
	for (int i = 0; i < 10; i++) {
		cin >> x;
		if (flag == 0 && abs(Min - x) <= Min) {
			Min -= x;
		}

		else {
			flag = 1;
			continue;
		}
	}
	cout << 100 - Min;
}

