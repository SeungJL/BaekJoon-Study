#include <iostream>
using namespace std;

long long dp_0[91]; // dp_1[i] : 길이가 i인 이친수 중, 0으로 끝나는 것의 개수
long long dp_1[91]; // dp_0[i] :   "    "    "    " ,  1로 끝나는 것의 개수

int main(void) {
	int N;
	cin >> N;

	dp_0[1] = 0;
	dp_0[2] = 1;

	dp_1[1] = 1;
	dp_1[2] = dp_0[1];

	for(int i=3; i<N; i++) {
		dp_0[i] = dp_0[i-1] + dp_0[i-2];
		dp_1[i] = dp_0[i-1]; // 전에 0으로 끝났을 때만 그 다음에 1이 올 수 있다
	}
	
	long long ans;
	if(N>1) ans = dp_1[N-1] + dp_0[N-1]*2;
	else ans = 1;
	cout << ans;

	return 0;
}