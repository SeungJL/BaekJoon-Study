#include <iostream>
#include <queue>
using namespace std;
int main(void) {
	int N, M;
	long long int res = 0;
	priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	for (int i = 0; i < M; i++) {
		long long int sum = 0;
		for (int j = 0; j < 2; j++) { // 제일 작은것 2개를 뽑고 합치기
			sum += pq.top();
			pq.pop();
		}
		for (int j = 0; j < 2; j++) {// 제일 작은것 2개 합을 다시 넣기
			pq.push(sum);
        }
	}


	while (!pq.empty()) { // 남은 모든 숫자 합하기
		res += pq.top();
		pq.pop();
	}

	cout << res;
}