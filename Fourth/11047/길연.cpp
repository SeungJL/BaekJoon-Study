// 백준 11047번 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	
	int num, won, cnt = 0;
	cin >> num >> won;
	vector<int> v(num);

	for (int i = 0; i < num; i++) 
		cin >> v[i];
	
	sort(v.begin(), v.end(), greater<>()); // 큰 단위부터 빼줘야함

	for (int i = 0; i < num; i++) {
		while (won - v[i] >= 0) { // 남은 금액 0원 이상일때 뺄 수 있을만큼
			cnt++;
			won -= v[i];
		}
	}
	
	cout << cnt << endl;

	return 0;
}

