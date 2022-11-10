#include <iostream>
#include <vector>
using namespace std;


int main(void) {
	int N, M;
	cin >> N >> M;
	vector<int> A(N+1);
	for(int i=1; i<=N; i++)
		cin >> A[i];

	int left=1, right=1;
	int total = 0, ans = 0;
	while((left<=right) && (right<=N+1)) {
		if(total < M)
			total += A[right++];
		else if(total > M)
			total -= A[left++];
		else {
			ans++;
			total += A[right++];
		}
	}
	cout << ans;

	return 0;
}