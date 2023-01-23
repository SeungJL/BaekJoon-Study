#include<iostream>

using namespace std;


int heap[100001] = { 0, };
int heapSize = 0;

void swap(int A, int B) {
	int temp = heap[A];
	heap[A] = heap[B];
	heap[B] = temp;
}
//작을 수록 위로
void insert(int x) {
	heap[++heapSize] = x;
	int cur = heapSize;
	while (cur != 1) {
		if (heap[cur] < heap[cur / 2]) {//부모가 자식보다 크면
			swap(cur, cur / 2);
			cur /= 2;
			continue;
		}
		break;
	}
}

int pop() {
	if (heapSize == 0)return 0;

	int result = heap[1];//배열 1부터사용
	heap[1] = heap[heapSize--];
	int cur = 1;

	int target;
	while (cur <= heapSize) {
		if (cur * 2 <= heapSize) {//
			target = cur * 2;
			if (cur * 2 + 1 <= heapSize && heap[cur * 2 + 1] <= heap[target]) {
				target = cur * 2 + 1;
			}


			if (heap[cur] > heap[target]) {
				swap(cur, target);
				cur = target;
				continue;
			}
		}
		break;
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x, n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 0)cout << pop() << '\n';
		else insert(x);
	}
}