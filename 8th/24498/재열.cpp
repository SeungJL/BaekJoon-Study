#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int height[N+1];
	int max = 0;
	for (int i = 1; i <= N; i++) {
		cin >> height[i];
		if (i >= 3 && i <= N) {		
			int now = height[i-1] + min(height[i-2], height[i]);
			if (now > max) max = now;
		}
		else if (i == 1) {		
			max = height[i];
		}
		else if (i == 2) {		
			if (height[i] > max) max = height[i];
		}
		
		if (i == N) {		
			if (height[i] > max) max = height[i];
		}
	}

	cout << max << endl;
	return 0;
}