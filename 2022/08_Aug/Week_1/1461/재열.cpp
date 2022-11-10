#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>		

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	
	int walked = 0, i, first_plus_index, max_move = 0;
	for (i = 0; i < N; i++) {
		if (arr[i] >= 0) break;
	}
	first_plus_index = i;

	for (i = 0; i < first_plus_index && i < N; i++) {
		walked += (abs(arr[i])*2);
		max_move = max(max_move, abs(arr[i]));
		for (int j = 0; j < M-1; j++) 
			i++;
	}

	for (i = N-1; i >= first_plus_index && i < N; i--) {
		walked += (arr[i]*2);
		max_move = max(max_move, abs(arr[i]));
		for (int j = 0; j < M-1; j++) 
			i--;
	}
	
	walked -= max_move;
	cout << walked << endl;
	return 0;
}
