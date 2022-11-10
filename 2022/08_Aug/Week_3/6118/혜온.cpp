#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
vector<int>graph[20001];
bool visit[20001];
int dis, shed, maxD;
vector<int>shedN;

void bfs(int n)
{
	queue<pair<int, int>>q;
	q.push(make_pair(n, 0));
	visit[n] = true;
	while (!q.empty())
	{
		int cur = q.front().first;
		int curD = q.front().second;
		if (curD > maxD)
		{
			maxD = curD;
			shedN.clear();
		}
		if (maxD == curD)
			shedN.push_back(cur);
		q.pop();
		for (int& next : graph[cur])
		{
			if (visit[next])continue;
			visit[next] = true;

			q.push(make_pair(next, curD + 1));


		}
	}
}

int main()
{
	cin >> N >> M;

	int A_i, B_i;
	for (int i = 0; i < M; i++)
	{
		cin >> A_i >> B_i;
		graph[A_i].push_back(B_i);
		graph[B_i].push_back(A_i);

	}

	bfs(1);
	sort(shedN.begin(), shedN.end());
	//첫 번째는 숨어야 하는 헛간 번호, 두 번째는 그 헛간까지의 거리를, 세 번째는 그 헛간과 같은 거리를 갖는 헛간의 개수
	cout << shedN.front() << " " << maxD << " " << shedN.size();

}