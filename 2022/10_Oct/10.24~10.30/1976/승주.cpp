#include <iostream>
#include <set>
using namespace std;

int N, M;
bool arr[201][201] = {};
bool visit[201] = {};
set <int> s;

void DFS(int start) {
	s.insert(start);
	visit[start] = 1;
	for (int i = 1; i <= N; i++) {
		if (visit[i]==0&&arr[start][i] == 1) {
			visit[i] = 1;
			DFS(i);
		}
	}
}

int main() {
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}
	int temp;
	cin >> temp;
	DFS(temp);

	set <int>::iterator iter;
	bool flag = 0;
	for (int i = 0; i < M - 1; i++) {
		cin >> temp;
		if (s.find(temp) == s.end()) flag = 1;
	}
	if (!flag) cout << "YES";
	else cout << "NO";
}
