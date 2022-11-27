// https://hio9105.tistory.com/entry/BOJ-11286-%EC%A0%88%EB%8C%93%EA%B0%92-%ED%9E%99-datastructures-priorityqueue

#include <iostream>
#include <vector>
// #include <queue> priority_queue 이용 시

using namespace std;

bool my_cmp(const int a, const int b) {
	// 절댓값
	int abs_a = abs(a), abs_b = abs(b);
	if (abs_a == abs_b) return a > b;
	return abs_a > abs_b;
}

void my_swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
}

class Heap {
    vector<int> heap;
    int size;
    const int root_idx = 1;

public:
	Heap() {
    	heap.push_back(0); // 힙의 루트 인덱스를 1로 하기 위함
    	size = 0;
    }
	void push(int x) {
        // 힙의 마지막에 새로운 노드 추가
        heap.push_back(x); size++;

        // 부모 노드와 값을 비교하며 새로운 노드를 올바른 위치로 재정렬
        int cur = size;
        while (cur > root_idx) {
            if (!my_cmp(heap[cur / 2], heap[cur])) break;
            my_swap(heap[cur / 2], heap[cur]);
            cur /= 2;
        }
    }
    void pop() {
        // 마지막 노드와 루트 노드를 swap한 후, 마지막에 위치한 루트 노드를 제거
        my_swap(heap[size], heap[root_idx]);
        heap.pop_back(); size--;

        // 루트에 위치된 노드를 자식 노드와 비교하며 올바른 위치로 재정렬
        int cur = root_idx;
        while (cur < size) {
            int child_idx = cur * 2;
            if (cur * 2 + 1 <= size && my_cmp(heap[child_idx], heap[cur * 2 + 1]))
                child_idx = cur * 2 + 1;

            if (child_idx > size || !my_cmp(heap[cur], heap[child_idx])) break;
            my_swap(heap[cur], heap[child_idx]);
            cur = child_idx;
        }
    }
    int top() { return heap[root_idx]; }
    bool empty() { return (size <= 0); }
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	int N, input;
	cin >> N;

	// priority_queue<int, vector<int>, decltype(&my_cmp)> PQ(my_cmp);	
	Heap PQ;
	while (N--) {
		cin >> input;
		if (input == 0) {
			if (!PQ.empty()) {
				cout << PQ.top() << "\n"; 
				PQ.pop();
			}
			else
				cout << "0\n";
		}
		else {
			PQ.push(input);
		}
	}
}