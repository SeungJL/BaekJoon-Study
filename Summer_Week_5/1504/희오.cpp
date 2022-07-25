// BOJ 1504

#include <iostream>
#include <vector>
#include <algorithm> // min

using namespace std;

#define INF 100000000

int N, E;
int **G;

int find_smallest(vector<int> dist, vector<bool> visited) {
	int min = INF, min_i = -1;
	for (int i=1; i<=N; i++) {
		if (!visited[i] && dist[i] < min) {
			min = dist[i];
			min_i = i;
		}
	}
	return (min_i);
}

vector<int> dijkstra(int sp) {

	vector<int> dist;
	for (int i=0; i<=N; i++)
		dist.push_back(G[sp][i]);
	vector<bool> visited(N+1, false);
	visited[0] = true;
	visited[sp] = true;

	while (1) {
		int k = find_smallest(dist, visited);
		if (k < 0) break;
		visited[k] = true;

		for (int j=1; j<=N; j++) {
			// if (visited[j]) continue;
			dist[j] = min(dist[j], dist[k] + G[k][j]);
		}
	}
	return (dist);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

//	freopen("input.txt", "rt", stdin);

	int V1, V2;

	cin >> N >> E;
	G = new int*[N+1];
	for (int i=0; i<=N; i++) {
		G[i] = new int[N+1];
		for (int j=0; j<=N; j++)
			G[i][j] = (i == j) ? 0 : INF;
	}
	while (E--) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a][b] = c;
		G[b][a] = c;
	}
	cin >> V1 >> V2;

	vector<int> SP_1 = dijkstra(1);
	vector<int> SP_N = dijkstra(N);
	vector<int> SP_V1 = dijkstra(V1);

	long long res = min(SP_1[V1] + SP_N[V2], SP_1[V2] + SP_N[V1]); 
	if (res >= INF || SP_V1[V2] >= INF)
		cout << "-1\n";
	else 
		cout << res + SP_V1[V2] << "\n";

}