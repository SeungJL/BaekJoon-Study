// 15903 

#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	/* input */
	int n, m, input;
	cin >> n >> m;

	priority_queue<unsigned long, vector<unsigned long>, greater<unsigned long>> PQ;
	while (n--) {
		cin >> input;
		PQ.push(input);
	}

	/* solve */
	while (m--) {
		// 현재 카드 중 가장 작은 두 수 - n1, n2
		unsigned long n1 = PQ.top(); PQ.pop();
		unsigned long n2 = PQ.top(); PQ.pop();

		// 그 두 장의 카드를 두 수의 합으로 덮어씌우기
		PQ.push(n1 + n2);
		PQ.push(n1 + n2);
	}

	// 최종 카드의 총합 구하기
	unsigned long long sum = 0;
	while (!PQ.empty()) {
		sum += PQ.top(); PQ.pop();
	}

	cout << sum << "\n";
}