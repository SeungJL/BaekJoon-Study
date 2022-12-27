#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INIT 0
#define A 1
#define B -1

/* solve: idx vertex가 속한 그래프가 이분그래프인지 확인하는 함수 
 *
 * parameters - G: 그래프 정보
 *            - color: 각 vertex의 그룹(색) 정보
 * return - 이분그래프이면 true, 아니면 false
 */
bool solve(vector<vector<int>> G, vector<int> &color, int idx) {
	queue<int> Q;
	Q.push(idx);
	color[idx] = A;

	while (!Q.empty()) {
		int cur_i = Q.front(); Q.pop();

		for (auto e : G[cur_i]) {
			if (color[cur_i] == color[e])	// edge의 양 끝 vertex가 같은 그룹에 속함
				return false;
			else if (color[e] == INIT) {	// INIT일 경우 이전에 그룹 체크를 하지 않았음을 의미, bfs의 체크배열의 기능 겸함
				color[e] = -color[cur_i];
				Q.push(e);
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	int K;
	cin >> K;
	
	while (K--) {
		/* input */
		int V, E, v1, v2;
		cin >> V >> E;
        
		vector<vector<int>> G(V+1);
		vector<int> color(V+1, INIT);
		while (E--) {
			cin >> v1 >> v2;
			G[v1].push_back(v2);
			G[v2].push_back(v1);
		}

		/* solve */
		bool isBipartite = true;
		// 하나의 연결그래프가 아닐 경우, 모든 그래프를 확인하기 위함 
		for (int i=1; i<=V; i++) {
			if (color[i] == INIT) {
				isBipartite = solve(G, color, i);
				if (!isBipartite) break;
			}
		}
        
        /* print answer */
		(isBipartite) ? cout << "YES\n" : cout << "NO\n";
	}