#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int N, K;
int visit[100001];
vector<int>a;
int road[100001];
vector<int>ans;

void bfs(int n)
{
	queue<pair<int, int>>q;
	q.push(make_pair(n, 0));
	visit[n] = true;
	while (!q.empty())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		//cout << cur << endl;
		if (cur == K)
		{
			cout << cnt << endl;

			return;
		}
		//visit[cur] = true;

		if (cur - 1 >= 0 && !visit[cur - 1])
		{
			q.push(make_pair(cur - 1, cnt + 1));
			road[cur - 1] = cur;
			visit[cur - 1] = true;

		}
		if (cur + 1 <= 100000 && !visit[cur + 1])
		{
			q.push(make_pair(cur + 1, cnt + 1));
			road[cur + 1] = cur;
			visit[cur + 1] = true;


		}
		if (cur * 2 >= 0 && cur * 2 <= 100000 && !visit[cur * 2])
		{
			q.push(make_pair(cur * 2, cnt + 1));
			road[cur * 2] = cur;
			visit[cur * 2] = true;


		}



	}

}

int main()
{

	cin >> N >> K;

	bfs(N);
	int temp = K;
	ans.push_back(K);
	while (temp != N) {
		ans.push_back(road[temp]);
		temp = road[temp];
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << " ";

}