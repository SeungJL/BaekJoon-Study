#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; 
	cin >> N;

	vector<int> A(N);
	vector<int> B(N);

	for (int i = 0; i < N; i++) 
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += (A[i]*B[i]);
	}

	cout << sum << endl;

	return 0;
}