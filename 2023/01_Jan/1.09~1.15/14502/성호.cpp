#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct point{
  int y;
  int x;
} Point;
int n, m, ans = 0;

void isMax(vector<vector<int> >&map)
{
  int now=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(map[i][j]==0)now++; 
    }
  }
  if (now > ans)
    ans = now;
  
}

void bfs(vector<vector<int>> map,queue<Point> q){
  int direct[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};

  while(!q.empty())
  {
    Point now = q.front();
    q.pop();

    for (int i = 0; i < 4;i++)
    {
      int dy = now.y + direct[i][0];
      int dx = now.x + direct[i][1];

      if(dy<0||dx<0||dy>=n||dx>=m)
        continue;
      if(map[dy][dx]!=0)
        continue;

      map[dy][dx] = 2;
      q.push({dy, dx});
    }
  }
  isMax(map);
}

void dfs(int level, vector<vector<int>> &map, queue<Point> &q)
{
  if(level==3){
    bfs(map,q);
    return;
  }
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(map[i][j]==0)
      {
        map[i][j]=1;
        dfs(level+1,map,q);
        map[i][j]=0;
      }
    }
  }
}

int main(void)
{
  cin >> n >> m;
  vector<vector<int>> map(n, vector<int>(m, 0));
    queue<Point> q;
  for (int i = 0; i < n;i++)
  {
    for (int j = 0; j < m;j++)
    {
      cin >> map[i][j];
      if(map[i][j]==2)
        q.push({i, j});
    }
  }
  dfs(0,map,q);
  cout << ans;
}