#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;
int k, v, e;
vector<int>graph[20001];

char arr[20001]; //0 : ¹æ¹® x, 1: Red, 2:Blue
int a, b;

void bfs(int n)
{
	queue<int>node;
	node.push(n);
	int c = 1;
	arr[n] = 1;
	while (!node.empty())
	{
		int t = node.front();
		node.pop();
		//c = ((c + 1) % 3 + (c + 1) / 3);//1-> 2 ,  2->1
		for (int i = 0; i < graph[t].size(); i++)
		{
			if (arr[graph[t][i]] == 0)
			{
				node.push(graph[t][i]);
				if (arr[t] == 1)
					arr[graph[t][i]] = 2;
				else if (arr[t] == 2)
					arr[graph[t][i]] = 1;
			}

		}

	}

}

bool check()
{
	for (int i = 1; i <= v; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			if (arr[i] == arr[graph[i][j]])
				return false;
		}
	}
	return true;
}
int main()
{
	cin >> k;
	while (k--)
	{
		cin >> v >> e;
		for (int i = 0; i < e; i++)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);

		}
		memset(arr, 0, sizeof(arr));
		for (int i = 1; i <= v; i++)
		{
			if (arr[i] == 0)
				bfs(i);
		}
		if (check())
			cout << "YES\n";
		else
			cout << "NO\n";
		memset(graph, 0, sizeof(graph));


	}
}