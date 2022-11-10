#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int arr[1001] = {}; // 0이면 뽑은 사람이 지는 경우

int DP(int x) {
	if (x <= 0) { return 1; }
	if (arr[x] == 1) { return 1; }
	arr[1] = 0;
	arr[3] = 0;
	arr[4] = 0;

	if (DP(x - 1) == 0 || DP(x - 3) == 0 || DP(x - 4) == 0) {
		arr[x] = 1;
		return 1;
	}
	else {
		arr[x] = 0;
		return 0;
	}

}


int main() {
	int N;
	cin >> N;
	if (DP(N) == 1) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}


}