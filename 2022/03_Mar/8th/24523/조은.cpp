#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> v(N+1), ans(N+1, -1);
	for(int i=1; i<=N; i++) cin >> v[i];
	
	for(int i=1; i<=N-1; )  {
		bool flag = false;
		int j;
		for(j=i+1; j<=N; j++) {
			if(v[i] != v[j]) {
				cout << j << ' ';
				flag = true;
				break;
			}
		}
		if(flag) { // i부터 ~ (j-1)까지 다 똑같
			for(int k=i+1; k<j; k++)
				cout << j << ' ';
			i = j;
		}
		else { // i번째부터 끝까지 다 같은 수인 경우
			for(int k=i; k<N; k++)
				cout << -1 << ' ';
			break;
		}
	}
	cout << -1;

	return 0;
}