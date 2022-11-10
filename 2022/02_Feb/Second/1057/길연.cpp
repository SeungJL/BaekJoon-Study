// 백준 1057번 토너먼트
// 2022년 01월 26일

#include <iostream> 
#include <algorithm>

using namespace std;

int main() {

	int num = 0, a = 0, b = 0;
	cin >> num >> a >> b;

	int round = 1;

	for (int i = 0; i < num; i++) {
		
		if (a == b) {
			round -= 1;
			break;
		}

		a = (a + 1) / 2;
		b = (b + 1) / 2;

		round += 1;
	}

	cout << round << endl;

	return 0;
}
