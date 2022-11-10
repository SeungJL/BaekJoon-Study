// 백준 3985번 롤 케이크

#include <iostream>
#include <vector>

using namespace std;

int realCake(int len, int n, vector<int> cake) {

	int realMax = 0;
	int maxRP = 0; // 실제로 가장 크게 받는 사람

	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= len; j++) {
			if (cake[j] == i)
				tmp++;
		}
		if (tmp > realMax ){
			realMax = tmp;
			maxRP = i;
		}
	}
	return maxRP;
}


int main() {
	

	int len, n;
	cin >> len >> n;

	int max = 0;
	int maxP = 0; // 예상하는 가장 크게 받는 사람
	vector<int> cake(len + 1);

	for (int i = 1; i <= n; i++) {

		int start, end;
		cin >> start >> end; // 케이크 범위

		int size = end - start + 1;

		if (size > max) { // 예상하는 가장 크게 받는 사람 확인
			max = size;
			maxP = i;
		}

		for (int j = start; j<= end; j++) { // 방청자 i에 대해서 케이크 표시
			if (cake[j] == 0)
				cake[j] = i; 
		}
	}
	int maxRP = realCake(len, n, cake);

	cout << maxP << endl;
	cout << maxRP << endl;

	return 0;
}
