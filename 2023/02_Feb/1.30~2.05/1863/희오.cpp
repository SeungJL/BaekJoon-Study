#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	int N, x, y; cin >> N;
	vector<int> stack(N+1, 0);
	int top = 0;
	int answer = 0;
	while (N--) {
		cin >> x >> y;
		while (top > 0 && stack[top] > y) {
			answer++;
			stack[top--] = 0;
		}
		if (stack[top] < y) stack[++top] = y;
	}
	answer += top;
	cout << answer << "\n";
}