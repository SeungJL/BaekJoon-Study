#include <iostream>
// #include <queue>

using namespace std;

class my_heap {
	int heap[100002] = {};
	int size = 0;
	const int root = 1;

	void swap(int &a, int &b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

public:
	bool empty() {
		return (size == 0);
	}
	int top() {
		return heap[root];
	}
	void push(int data) {
		size++;
		heap[size] = data;

		int cur = size;
		while (cur/2 >= root && heap[cur] < heap[cur/2]) {
			swap(heap[cur], heap[cur/2]);
			cur /= 2;	
		}
	}
	void pop() {
		swap(heap[root], heap[size]);
		heap[size] = 0; size--;

		int cur = root;
		while (1) {
			int child_i = 0;

			if (cur * 2 <= size)
				child_i = cur * 2;
			if (cur * 2 + 1 <= size && heap[cur * 2 + 1] < heap[child_i])
				child_i = cur * 2 + 1;
			
			if (child_i == 0 || heap[cur] < heap[child_i]) break;
			swap(heap[cur], heap[child_i]);
			cur = child_i;
		}
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	int n, input;
	cin >> n;

	my_heap min_heap;
	// priority_queue<int, vector<int>, greater<int>> min_heap;
	while (n--) {
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