#include <iostream>
using namespace std;
#define MAX 10001

bool self_num[MAX];

int d(int n) {
	int res = n;
	int t = n;
	while(t) {
		res += t%10;
		t /= 10;
	}

	return res;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill_n(self_num, MAX, true);	
	
	for (int i = 1; i < MAX; i++) {
		int n = d(i);
		if(n < MAX) self_num[n] = false;
	}
	
	for (int i = 1; i < MAX; i++) {
		if(self_num[i]) cout << i << '\n';
	}

	return 0;
}