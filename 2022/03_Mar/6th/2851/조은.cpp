#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a[10];
	for(int i=0; i<10; i++) {
		cin >> a[i];
	}
	int i=0, sum=0;
	for(int i=0; ; i++) {
		if(abs(sum-100) >= abs(sum+a[i]-100)) {
			sum += a[i];
		}
		else break;
	}
	cout << sum;

	return 0;
}