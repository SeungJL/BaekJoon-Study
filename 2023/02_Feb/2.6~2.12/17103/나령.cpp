#include <iostream>
#define N 1000001
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	bool arr[N];
	for(int i=0; i<N; i++) {
		arr[i] = true;
	}
	arr[0] = arr[1] = false;
	
	for(int i=2; i*i<N; i++) {
		if(arr[i]) {
			for(int j=i*2; j<=N; j+=i) {
				arr[j] = false;
			}
		}
	}
	
	while(t--) {
		int result = 0;
		int n;
		cin >> n;
		
		for(int i=0; i<=n/2; i++) {
			int a = i;
			int b = n - i;
			
			if(arr[a] && arr[b]) {
				result++;
			}
		}
		
		cout << result << '\n';
	}
	
	return 0;
}