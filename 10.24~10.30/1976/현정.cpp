/*
https://www.acmicpc.net/problem/1976
백준 1976 : 여행가자
각 경로 간 이동가능한지 여부를 BFS로 판단하여 그 값을 반환한다
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
*@brief start->end 까지 경로로 이동할 수 있는지 BFS로 판단하는 함수

*@param start 시작 노드 인덱스값 (0~n-1)
*@param end 도착 노드 인덱스값
*@param map 연결 정보를 가리키는 배열
*@param n 도시의 개수를 가리키는 값

*@return start->end 까지 이동할 수 있으면 True
*/
bool IsTravable(int start, int end, vector<vector<bool>> map,int n){
	vector<bool> isvisited(n);
	fill(isvisited.begin(), isvisited.end(), false);
	queue<int> q;
	q.push(start);
	isvisited[start] = true;

	while (!q.empty()) {
		int nowpos = q.front();
		q.pop();

		//도착 값에 도달하면 true를 반환
		if (nowpos == end) {
			return true;
		}
		for (int i = 0; i < n; i++) {
			if (map[nowpos][i]&&!isvisited[i]){
				q.push(i);
				isvisited[i] = true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<bool>> map(n);
	for (int i = 0; i < n; i++) {
		map[i].resize(n);
		for (int j = 0; j < n; j++) {
			bool input;
			cin >> input;
			map[i][j] = input;
		}
	}

	int start, end;
	cin >> start;
	for (int i = 0; i < m-1; i++) {
		cin >> end;
		if (!IsTravable(start-1, end-1, map, n)) {
			cout << "NO\n";
			return false;
		}
		start = end;
	}
	cout << "YES\n";
	return 0;
}
