#include <iostream>
#define MAX 1001
using namespace std;

int main() {
	int N, L;
	cin >> N >> L;
	bool leak[MAX] = { false, };
	int n;
	for(int i=0; i<N; i++) {
		cin >> n;
		leak[n] = true;
	}
	
	int ans = 0;
	for(int i=0; i<MAX; ) {
		if(leak[i]) {
			ans++;
			i += L;
			continue;
		}
		i++;
	}

	cout << ans;
	return 0;
}