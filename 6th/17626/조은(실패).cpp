#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int cnt = 2100000000;
	for (int i=(int)sqrt(n); i>=1; i--) {
		int sum = i*i;
		if(sum == n) {
			cout << 1;
			break;
		}

		int tmp = 1;
		for (int j=i-1; j>=1; j--) {
			int k = j*j;
			if(sum+k == n) {
				tmp++;
				cnt = min(cnt, tmp);
				break;
			}
			else if(sum+k < n) {
				sum += k;
				tmp++;
			}	
		}
	}
	cout << cnt;

	return 0;
}