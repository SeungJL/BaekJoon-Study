// 1927 

#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int N, input;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> min_heap;

	while (N--) {
		cin >> input;
		if (input > 0) 
			min_heap.push(input);
		else {
			if (min_heap.empty()) 
				cout << "0\n";
			else {
				cout << min_heap.top() << "\n";
				min_heap.pop();
			}
		}
	}
}