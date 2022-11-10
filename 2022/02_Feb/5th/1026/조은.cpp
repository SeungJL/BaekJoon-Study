#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int N; cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	} // 입력
	
	sort(A.begin(), A.end()); // A 오름차순 정렬
	sort(B.begin(), B.end(), greater<int>()); // B 내림차순 정렬
	
	int S = 0;
	for (int i = 0; i < N; i++) {
		S += A[i] * B[i];
	}
	cout << S;

	return 0;
}
