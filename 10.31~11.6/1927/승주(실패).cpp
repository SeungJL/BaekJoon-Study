#include <iostream>

using namespace std;

typedef struct {
	int arr[100001];
	int size;
}heap;

void insertHeap(heap *hp,int data) {
	int here = ++hp->size;
	while (here!=1&&data<hp->arr[here/2]) {
		//자식노드와 부모노드를 비교하는건 맞지만, 자식노드에 아직 값이 없다
		//자식 노드에 위치할 data와 부모노드를 비교한다
		hp->arr[here] = hp->arr[here / 2];
		here /= 2;
	}
	hp->arr[here] = data;
}
void swap(int* a, int* b) {
	int tmp = *a;
	*b=*a;
	*a = tmp;
}
int deleteHeap(heap* hp) {
	// 자식 노드가 두개이기 때문에 둘 다 생각을 해줘야 한다
	if (hp->size == 0) { return 0; }
	int ret = hp->arr[1];
	hp->arr[1] = hp->arr[hp->size--];
	int parent=1;
	int child=2;
	while (1) {
        child=parent*2;
		//두 자식노드 중 하나라도 작은 값이 있으면 진행 될 것이다
		//while문에 무리해서 조건을 넣지 말자. 일반적인것만.
		if (child + 1 <= hp->size && hp->arr[child] > hp->arr[child + 1])
			child++;
		if (child > hp->size || hp->arr[child] > hp->arr[parent]) break;
		//왜인지 모르겠지만 자식과 부모가 같을때에도 실행시켜줘야 함
		swap(&hp->arr[parent], &hp->arr[child]);
		parent = child;
	}
	return ret;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	heap H;
	H.size = 0;
	int Input;
	for (int i = 0; i < N; i++) {
		cin >> Input;
		if (Input > 0) insertHeap(&H, Input);
		else cout<<deleteHeap(&H) << '\n';
		//테스트를 위해 썼던 다른 것들은 모두 잘 지우자
	}
}