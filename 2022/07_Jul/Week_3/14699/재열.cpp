#include <iostream>
#include <vector>
#include <memory.h>	

using namespace std;

vector<int> graph[5000];
int dp[5000];		
bool is_visited[5000];
int height[5000];

int dfs(int now) {
	if (dp[now]) 
		return dp[now];
	is_visited[now] = true;
	int max_count = 1;
	for (int i = 0; i < graph[now].size(); i++) {
		if (!is_visited[graph[now][i]]) {	
			max_count = max(max_count, dfs(graph[now][i])+1);
		}
	}
	is_visited[now] = false;
	return dp[now] = max_count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> height[i];
		graph[i] = vector<int>();
	}
	int temp1, temp2;
	for (int i = 0; i < M; i++) {
		cin >> temp1 >> temp2;
		if (height[temp1-1] < height[temp2-1]) graph[temp1-1].push_back(temp2-1);
		if (height[temp2-1] < height[temp1-1]) graph[temp2-1].push_back(temp1-1);
	}
	for (int i = 0; i < N; i++) {
		cout << dfs(i) << endl;
	}
	return 0;
}
