// 백준 4673번 셀프 넘버

#include <iostream>
#include <vector>

using namespace std;
bool check[10001] = { 0 };

int func(int n) { // n과 n의 각 자리 수를 더하는 함수 
	int sum;
	sum = n + n / 1000 + n % 1000 / 100 + n % 100 / 10 + n % 10;
	return sum;
}

void selfNum() { // 셀프넘버가 아닌걸 체킹하는 함수
	int sum;
	check[1] = 0;
	for (int i = 0; i < 10000; i++) {
		if (i < 10000) { 
			sum = func(i);
			if (sum < 10000) // 셀프넘버가 아니면 체크
				check[sum] = 1;
		}	
	}
}
int main() {
	
	selfNum();

	for (int i = 1; i < 10000; i++) {
		if (check[i] == 0) // 셀프 넘버 출력
			cout << i << endl;
	}

	return 0;
}
