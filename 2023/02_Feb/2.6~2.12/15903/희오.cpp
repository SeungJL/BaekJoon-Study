#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int n, m, input;
	cin >> n >> m;

	priority_queue<unsigned long, vector<unsigned long>, greater<unsigned long>> PQ;
	while (n--) {
		cin >> input;
		PQ.push(input);
	}

	while (m--) {
		unsigned long n1 = PQ.top(); PQ.pop();
		unsigned long n2 = PQ.top(); PQ.pop();

		PQ.push(n1 + n2);
		PQ.push(n1 + n2);
	}

	unsigned long long sum = 0;
	while (!PQ.empty()) {
		sum += PQ.top(); PQ.pop();
	}

	cout << sum << "\n";
}
