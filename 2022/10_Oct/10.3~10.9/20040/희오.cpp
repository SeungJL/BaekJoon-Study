// 20040

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

/* my_find: 연결된 노드 중 가장 최상위 노드, parent 노드를 찾는 함수
 *
 * parameter - x: 부모노드를 찾고자 하는 노드 번호
 * return: x의 부모 노드
 */
int my_find(int x) {
	if (arr[x] == x) return x;
	return my_find(arr[x]);
}

/* my_union: 두 개의 노드를 하나의 집합으로 연결하는 함수
 *
 * parameter - a, b: 연결하고자 하는 두 노드
 * return - 싸이클 여부, 두 노드가 싸이클일 경우 true 리턴
 */
bool my_union(int a, int b) {
	int p_a = my_find(a);
	int p_b = my_find(b);
	if (p_a == p_b) return true;
	(p_a <= p_b) ? arr[p_b] = p_a : arr[p_a] = p_b;
	return (p_a == p_b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	/* input */
	int N, M;
	cin >> N >> M;
	for (int i=0; i<N; i++) 
		arr.push_back(i);

	/* solve */
	int a, b;
	bool isCycle = false;
	for (int i=1; i<=M; i++) {
		cin >> a >> b;
		if (isCycle) continue;
		isCycle = my_union(a, b);
		if (isCycle)
			cout << i << "\n";
	}
	if (!isCycle) cout << "0\n";
}