#include <iostream>
#include <vector>

using namespace std;

int N, M; // N: 도시의 수, M: 여행 계획에 속한 도시의 수
vector<int> parent; // i번째 도시 노드와 연결된 상위 도시 노드
                    // 두 도시의 가장 상위 도시 노드(root)가 같을 경우 연결되어 있음을 의미함

/* my_find(): x와 연결된 가장 상위 노드를 찾는 함수
 *
 * parameters - x: 상위 노드 root를 찾고자 하는 도시 번호
 * return - x와 연결된 root
 */
int my_find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = my_find(parent[x]);
}

/* my_union(): 두 도시를 연결하여 각각의 도시가 포함되어 있는 두 집합을 하나로 합쳐주는 함수
 *
 * parameters - a, b: 연결하고자 하는 두 도시 번호
 * no return
 */
void my_union(int a, int b) {
	int p_a = my_find(a);
	int p_b = my_find(b);

	if (p_a != p_b)
		parent[p_b] = parent[p_a];
}

/* isConnected(): 두 도시가 연결되어 있는지(하나의 집합에 포함되어 있는지) 확인하는 함수
 *
 * parameters- a, b: 연결되어 있는지 확인하고자 하는 두 도시 번호
 * return - 연결되어 있으면 true, 연결되어 있지 않으면 false
 */
bool isConnected(int a, int b) {
	return (my_find(a) == my_find(b));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "rt", stdin);

	/* get N, M input & init parent array */
	cin >> N >> M;
	for (int i=0; i<=N; i++)
		parent.push_back(i);
	
	/* get graph input & union */
	int input;
	for (int r=1; r<=N; r++) {
		for (int c=1; c<=N; c++) {
			cin >> input;
			if (input && r < c)
				my_union(r, c);
		}
	}

	/* solve */
	int from, to; //
	cin >> from; M--;
	while (M--) {
		cin >> to;
		if (!isConnected(from, to)) {
			cout << "NO\n";
			return 0;
		}
		from = to;
	}
	cout << "YES\n";
}
