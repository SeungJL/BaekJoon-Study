#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	//2와 5가 곱해질 때 마다 0이 하나 생김
	//따라서 1부터 N까지 소인수분해했을 때 총 등장한 2의 개수와 5의 개수를 구하면 됨.

	int count2 = 0;
	int count5 = 0;
	for (int i = 1; i <= N; i++) {
		int now = i;
		//2로 나누어떨어지지 않아질 때 까지 2로 나눔
		while (now % 2 == 0) {
			now /= 2;
			count2++;
		}
		//5로 나누어떨어지지 않을 때 까지 5로 나눔
		while (now % 5 == 0) {
			now /= 5;
			count5++;
		}
	}
	cout << min(count2, count5) << endl;
	
	return 0;
}