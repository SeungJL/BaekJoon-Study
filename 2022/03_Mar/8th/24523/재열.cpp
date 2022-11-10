#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int arr[N+1];
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	int result[N+1];
	result[N] = -1;
	int recent = arr[N];
	int changed = -2;
	for (int index = N-1; index >= 1; index--) {		
		if (arr[index] == recent) {
			result[index] = (changed+1);
		}
		else {
			result[index] = (index+1);
			changed = index;
		}
		recent = arr[index];
	}	

	for (int i = 1; i <= N; i++) {
		cout << result[i] << ' ';
	}
	cout << endl;
	return 0;
}