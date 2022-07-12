#include <iostream>

using namespace std;

int main(void)
{
	int T, M, N, x, y, i;
	cin >> T;
	while (T--) {
		cin >> M >> N >> x >> y;

		for (i = x; i <= M*N; i+=M) {
			int tmp = (i%N == 0) ? N : i % N;
			if (tmp == y) {
				cout << i << '\n';
				break;
			}
		}
		if(i>M*N)
		cout << -1 << '\n';
	}

	

	return 0;
}