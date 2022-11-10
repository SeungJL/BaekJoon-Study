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
	unsigned long long N, R;
	cin >> N >> R;
	if (N == 1) {
		cout << 2 * R;
		return 0;
	}

	cout << N + 2 * R - 1;

}
