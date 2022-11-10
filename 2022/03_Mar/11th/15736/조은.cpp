#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	int cnt = 0;
	for(int i=1; i*i<=N; i++)
		cnt++;

	cout << cnt;

	return 0;
}