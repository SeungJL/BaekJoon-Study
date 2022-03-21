#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> A[N];
	
	int i = 0, sum = 0;
	int input;
	while (true) {
		cin >> input;
		sum += input;
		A[i].push_back(input);
		if (sum >= 27) {i++; sum=0;}
		if (i >= N) break;
	}

	int now = 0;
	for (int i = 0; i < N; i++) {
		if (now < 13) {
			int leftSum = 0;
			int rightSum = 0;
			for (int j = 0; j < A[i].size(); j++){
				if (j % 2 == 0) {
					rightSum += A[i][j];
				}
				else {
					leftSum += A[i][j];
					if (leftSum > now) break;
				}
			}
			now += rightSum;
		}
		else {
			now -= 13;
			int leftSum = 0;
			int rightSum = 0;
			for (int j = 0; j < A[i].size(); j++) {
				if (j % 2 == 0) {
					rightSum += A[i][j];
					if (rightSum > now) break;
				}
				else {
					leftSum += A[i][j];
				}
			}
			now += leftSum;
		}
	}

	cout << now+1 << endl;
	return 0;
}