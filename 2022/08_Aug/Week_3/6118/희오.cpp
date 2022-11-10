// BOJ 6118

#include <iostream>
#include <queue>

using namespace std;

#define INF 100000

struct Vertex {
	int num, dist;

	Vertex(int _n, int _d) : num(_n), dist(_d) {};

	bool operator< (const Vertex &a) const {
		return (dist > a.dist);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	// get input
	int N, M;
	vector<int> G[20001];

	cin >> N >> M;
	for(int i=0; i<M; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	// solve
	priority_queue<Vertex> PQ;
	vector<int> SP(N+1, INF);
	vector<bool> visited(N, false);

	visited[0] = true;
	PQ.push(Vertex(1, 0));
	SP[1] = 0;

	while (!PQ.empty()) {
		Vertex nearest = PQ.top();
		PQ.pop();
		
		if (visited[nearest.num]) continue;
		visited[nearest.num] = true;

		for(auto to : G[nearest.num]) {
			if (nearest.dist + 1 < SP[to]) {
				SP[to] = nearest.dist + 1;
				PQ.push(Vertex(to, SP[to]));	
			}
		}
	}

	int max_dist = 0, max_v, max_cnt;
	for (int i=2; i<=N; i++) {
		if (SP[i] > max_dist) {
			max_dist = SP[i];
			max_v = i;
			max_cnt = 1;
		}
		else if (SP[i] == max_dist) 
			max_cnt++;
	}

	cout << max_v << " " << max_dist << " " << max_cnt << "\n";

}