#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);
	int N, M, input, start, end, acc_sum;
	cin >> N >> M;
	int* sum = new int[N+2];
	acc_sum = sum[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		acc_sum += input;
		sum[i] = acc_sum;
	}
	for (int i = 1; i <= M; i++) {
		cin >> start >> end;
		cout << sum[end] - sum[start-1] << '\n';
	}
	delete[] sum;
	return 0;
}
