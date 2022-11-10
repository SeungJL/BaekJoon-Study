// 백준 1010번 
// 2022년 2월 1일

#include <iostream>

using namespace std;

int main() {

	int test;
	cin >> test;

	while (test--) {
		int n, m;
		cin >> n >> m;

		long long ans = 1;
		
		/*		n // m  -> mCn		*/
		int c = 1;
		for (int i = m; i > (m - n); i--) {
			ans *= i;
			ans /= c++;
		}

		cout << ans << endl;
	}
}
