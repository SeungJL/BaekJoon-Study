// https://hio9105.tistory.com/entry/BOJ-1715-%EC%B9%B4%EB%93%9C-%EC%A0%95%EB%A0%AC%ED%95%98%EA%B8%B0-datastructures-greedy-priorityqueue

#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	int N, input;
	priority_queue<int, vector<int>, greater<int>> cardSet;

	cin >> N;
	while (N--) {
		cin >> input;
		cardSet.push(input);
	}

	int a, b;
	int answer = 0;
	while (cardSet.size() > 1) {
		a = cardSet.top(); cardSet.pop(); 
		b = cardSet.top(); cardSet.pop();
		cardSet.push(a + b);
		answer += a + b;
	}

	cout << answer << "\n";
}