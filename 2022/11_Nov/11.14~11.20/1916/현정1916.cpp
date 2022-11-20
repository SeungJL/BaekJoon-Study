/*
https://www.acmicpc.net/problem/1916
백준 1916 : 최소비용 구하기
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
* @brief from부터 to 까지의 버스 경로 비용의 최솟값들을 cost에 담아 계산하는 함수
* 
* 우선순위 Queue를 사용하여 cost 값을 최솟값부터 정렬한다. 
* 우선순위는 숫자가 클수록 top 에 위치하게 되므로 cost에 -1을 곱해 넣어준다
* 또는, 우선순위 큐의 비교함수를 Grater로 설정하면 된다
* 
* @param {vector<vector<pair<int, int>>>} map : 버스 경로들을 담은 배열. <도착값, cost> 순
* @param {int*} cost : i번째 도시까지의 최소비용을 담을 cost 배열 포인터. 배열 내부 값은 0x3f3f3f3f 로 초기화되어있음
* @param {int} from : 경로 시작 도시
* @param {int} to : 최종 도착 도시
*/
void FindMinCost(vector<vector<pair<int, int>>> map, int* cost, int from, int to) {
	priority_queue<pair<int, int>> pq; //<현재까지의 cost * (-1), 현재의 pos>를 cost 순으로 우선순위정렬
	pq.push(make_pair(0, from));
	cost[from] = 0;

	while (!pq.empty()) {
		int nowcost = -pq.top().first;
		int nowpos = pq.top().second;
		pq.pop();

		if (cost[nowpos] < nowcost)	continue; //이 부분이 없으면, 비효율적인 루트들까지 다 돌게되어 시간초과가 된다

		for (int i = 0; i < map[nowpos].size(); i++) {
			int next = map[nowpos].at(i).first;
			int ncost = nowcost + map[nowpos].at(i).second;
			if (cost[next] > ncost) {
				cost[next] = ncost;
				pq.push(make_pair(-ncost, next)); //우선순위 큐에 가장 작은값 순서로 정렬되게 하기 위함
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int,int>>> map(n + 1); //같은 경로의 버스가 여러 대일 수 있으므로, 단순 배열을 사용하면 안된다
	int* cost = new int[n+1];
	for (int i = 0; i <= n; i++) {
		map[i].resize(n + 1);
		cost[i] = 0x3f3f3f3f;
	}

	for (int i = 0; i < m; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		map[x].push_back(make_pair(y, cost));
	}

	vector<bool> isvisited(n + 1);

	int from, to;
	cin >> from >> to;

	FindMinCost(map, cost, from, to);

	cout << cost[to] << "\n";
}
