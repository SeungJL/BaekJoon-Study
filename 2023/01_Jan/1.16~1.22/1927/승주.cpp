#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	multiset <int> S;
	int N;
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x != 0) {
			S.insert(x);
		}
		else {
			if (S.size() == 0) {
				cout << 0 << "\n";
				continue;
			}
			else {
				cout << *S.begin() << '\n';
				S.erase(S.begin());

			}
		}
	}
}