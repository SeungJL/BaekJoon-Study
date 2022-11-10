

#include <iostream>
using namespace std;

/*
* @brief 사이클 배열의 값으로부터 정점 x의 부모 노드 번호를 반환하는 함수
* 
* @param int parent[] : 사이클 부모 값 저장하는 배열
* @param int x : 현재 부모를 알고자 하는 정점
* 
* @return 정점 x의 root 부모 노드의 번호를 반환
*/
int GetParent(int parent[], int x) {
	if (parent[x] == x)	return x;
	return parent[x] = GetParent(parent, parent[x]);
}

/*
* @brief UnionParent() : 사이클 배열에서 a와 b 정점의 부모를 연결하는 함수 (더 작은 정점 번호를 부모로 채택한다)
* 
* @param int parent[] : 사이클 부모 값 저장하는 배열
* @param int a, b : 연결하고자 하는 두 정점의 번호
* 
*/
void UnionParent(int parent[], int a, int b) {
	a = GetParent(parent, a);
	b = GetParent(parent, b);
	if (a <= b)	parent[b] = a;
	else parent[a] = b;
	return;
}

/*
* @breif 두 정점의 부모가 같은지 체크하는 함수
* 
* @param int parent[] : 사이클 부모 값 저장하는 배열
* @param int a, b : 비교하고자 하는 두 정점의 번호
* 
* @return 두 정점의 부모가 같다면 true, 아니면 false
*/
bool IsEqualParent(int parent[], int a, int b) {
	a = GetParent(parent, a);
	b = GetParent(parent, b);
	return (a == b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

  //동적 배열 생성
	int* parent;
	parent = (int*) malloc(n * sizeof(int)); 

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;

    // 두 정점의 부모가 같다면, 현재 선분을 그으면서 사이클이 완성되므로 종료
		if (IsEqualParent(parent, x, y)) {
			cout << i << "\n";
			return 0;
		}
    // 정점의 부모가 다르다면 두 정점을 연결한다
		else UnionParent(parent, x, y);
	}
	cout << 0 << "\n";
	return 0;
}

