#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct node{
	int y;
	int x;
}Point;

vector<Point> chicken;
vector<Point> house;
int n,m;
int direct[4][2]={-1,0,1,0,0,1,0,-1};
int output=21e8;

void flood_fill(vector<vector<int>> map, vector<Point>::iterator iter,int ans)
{
	if(iter==house.end()){
		output=min(ans,output);
		return;
	}

	queue<Point> q;
	q.push({iter->y,iter->x});

	vector<vector<int>> visited(n,vector<int>(n,0));
	visited[iter->y][iter->x]=1;

	while(!q.empty()){
		Point now = q.front();
		q.pop();

		for(int i=0;i<4;i++)
		{
			int dy=now.y+direct[i][0];
			int dx=now.x+direct[i][1];

			if(dy<0||dx<0||dy>=n||dx>=n)continue;
			if(visited[dy][dx]!=0)continue;

			visited[dy][dx]=visited[now.y][now.x]+1;
			if(map[dy][dx]==2)
				flood_fill(map,iter+1,ans+visited[now.y][now.x]);
			q.push({dy,dx});
		}
	}
}

void dfs(int level,vector<vector<int>> &map,vector<Point>::iterator iter){
	if(level==m)
	{
		flood_fill(map,house.begin(),0);
		return;
	}
	if(iter==chicken.end())return;

	map[iter->y][iter->x]=0;
	dfs(level-1,map,iter+1);

	map[iter->y][iter->x]=2;
	dfs(level,map,iter+1);
}

int main(void)	
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin>>n>>m;
	vector<vector<int>> map(n,vector<int>(n,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>map[i][j];
			if(map[i][j]==1)
				house.push_back({i,j});
			else if(map[i][j]==2)
				chicken.push_back({i,j});
		}
	}
	dfs(chicken.size(),map,chicken.begin());
	cout<<output<<endl;
}