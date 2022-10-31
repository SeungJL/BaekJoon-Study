#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[201][201] = {};
bool visit[201] = {};
vector<int> V;

void DFS(int start) {
	visit[start] = 1;
	for (int i = 0; i < N; i++) {
		if (visit[i] == 0 && arr[start][i] == 1) {
			visit[i] = 1;
			V.push_back(i);
			DFS(i);
		}
	}
}

int main() {
	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	int routine[1001];
	for (int i = 0; i < M; i++)
		cin >> routine[i];
	sort(routine, routine + M);
	V.push_back(routine[0] - 1);

	DFS(routine[0] - 1);
	sort(V.begin(), V.end());

	int j = 0;
	for (int i = 0; i < M; i++) {
		if (routine[i] - 1 == V[j]) {
			continue;
		}
		else if (j < V.size() - 1 && routine[i] - 1 == V[j + 1]) {
			j++;
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

}