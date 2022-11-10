#include <iostream>
#include <set>
#include <string>

using namespace std;

int graph[5][5];	
set<int> results;

void dfs(int depth, int num, int a, int b) {
	if (a < 0 || a >= 5 || b < 0 || b >= 5) return;
	if (depth == 6) {		//깊이 5에 도달하면(5개의 숫자 쌓이면)
		results.insert(num);		//results에 nowResult추가 (중복시 자동으로 추가 안됨)
		return;
	}

	num = (num * 10 + graph[a][b]);		//기존에 있던거에 10을 곱하고 현 칸에 있는 것을 일의 자리로

	dfs(depth+1, num, a-1, b);
	dfs(depth+1, num, a, b-1);
	dfs(depth+1, num, a+1, b);
	dfs(depth+1, num, a, b+1);
} 


int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			//점 (i,j)로부터 시작하는 dfs수행
			dfs(0, 0, i, j);
		}
	}

	cout << results.size() << endl;
	return 0;
}
