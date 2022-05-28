#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> S;
bool visited[2000000];

void dfs(int depth, int sum) {
	if(depth == N) {
		visited[sum] = true;
		return;
	}
	dfs(depth+1, sum);
	dfs(depth+1, sum + S[depth]);
}

int main(void) {
	cin >> N;
	int n;
	for(int i=0 ;i<N; i++) {
		cin >> n;
		S.push_back(n);
	}
	
	dfs(0, 0);

	int ans = 1;
	while(true) {
		if(visited[ans] == false) {
			cout << ans;
			break;
		}
		ans++;
	}
}