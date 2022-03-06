#include <iostream>
#include <cmath>
using namespace std;

/* N!에 2,5가 곱해진 개수를 각각 카운트해서 그중 더 작은 값을 반환 */
int countZero(int n) {
	int e=0, o=0;
	for(int i=2; i<=n; i++) {
		int t = i;
		while(!(t%2)) {
			e++;
			t /= 2;
		}
		while(!(t%5)) {
			o++;
			t /= 5;
		}
	}

	return min(e,o);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int ans = countZero(N);
	cout << ans;

	return 0;
}