#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

vector<list<int>> graph;
int results[1000001];		

void dfs(int prevNum, int nowNum) {		//DFS수행.
	for (auto x : graph[nowNum]) {
		if (x != prevNum) 		//이전 노드가 아니기만 한다면 이동.
			dfs(nowNum, x);
	}
	
	results[nowNum] = prevNum;	//수행 마치고 올라가기 전 등록
}

int main() {
	int N;
	cin >> N;
	graph.resize(N+1);
	for (int i = 0; i <= N; i++) {
		list<int> l;
		graph[i] = l;
	}

	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (auto x : graph[1]) {
		dfs(1, x);
	}

	for (int i = 2; i <= N; i++) {
		cout << results[i] << '\n';
	}

	return 0;
}