#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct point
{
  int y;
  int x;
} Point;

struct Dice
{
  int BACK = 2,LEFT = 4,UP = 1,RIGHT = 3,FRONT = 5,DOWN = 6,nowY = 1,nowX = 1;
  string nextDirection = "right";
  void turnRight()
  {
    int temp = LEFT;
    LEFT = DOWN;
    DOWN = RIGHT;
    RIGHT = UP;
    UP = temp;
  }
  void turnLeft(){
    int temp = LEFT;
    LEFT = UP;
    UP = RIGHT;
    RIGHT = DOWN;
    DOWN = temp;
  }
  void turnUP(){
    int temp = BACK;
    BACK = UP;
    UP = FRONT;
    FRONT = DOWN;
    DOWN = temp;
  }
  void turnDown(){
    int temp = BACK;
    BACK = DOWN;
    DOWN = FRONT;
    FRONT = UP;
    UP = temp;
  }
}dice;
int direct[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
int answer=0, n, m, num;

void isGoodToGo(){
  if(dice.nextDirection=="right"&&dice.nowX+1>m)dice.nextDirection = "left";
  else if(dice.nextDirection=="left"&&dice.nowX-1==0)dice.nextDirection = "right";
  else if(dice.nextDirection=="up"&&dice.nowY-1==0)dice.nextDirection = "down";
  else if(dice.nextDirection=="down"&&dice.nowY+1>n)dice.nextDirection = "up";
}

void GO(vector<vector<int>> &map){
  isGoodToGo();
  if (dice.nextDirection == "right")
  {
    dice.nowX += 1;
    dice.turnRight();
    if(dice.DOWN>map[dice.nowY][dice.nowX]){
      dice.nextDirection = "down";
    }
    else if(dice.DOWN<map[dice.nowY][dice.nowX])
    {
      dice.nextDirection = "up";
    }
  }
  else if(dice.nextDirection=="left"){
    dice.nowX -= 1;
    dice.turnLeft();
    if(dice.DOWN>map[dice.nowY][dice.nowX]){
      dice.nextDirection = "up";
    }
    else if(dice.DOWN<map[dice.nowY][dice.nowX])
    {
      dice.nextDirection = "down";
    }
  }
  else if(dice.nextDirection=="up"){
    dice.nowY -= 1;
    dice.turnUP();
    if(dice.DOWN>map[dice.nowY][dice.nowX]){
      dice.nextDirection = "right";
    }
    else if(dice.DOWN<map[dice.nowY][dice.nowX])
    {
      dice.nextDirection = "left";
    }
  }
  else if(dice.nextDirection=="down"){
    dice.nowY+= 1;
    dice.turnDown();
    if(dice.DOWN>map[dice.nowY][dice.nowX]){
      dice.nextDirection = "left";
    }
    else if(dice.DOWN<map[dice.nowY][dice.nowX])
    {
      dice.nextDirection = "right";
    }
  }
}

void BFS(vector<vector<int>> &map){
  int num = 1;
  queue<Point> q;
  q.push({dice.nowY, dice.nowX});
  vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));
  visited[dice.nowY][dice.nowX] = true;

  while(!q.empty()){
    Point now = q.front();
    q.pop();

    for (int i = 0; i < 4;i++)
    {
      int nowY = now.y + direct[i][0];
      int nowX = now.x + direct[i][1];

      if(nowY<1||nowX<1||nowY>n||nowX>m)
        continue;
      if(visited[nowY][nowX]==true)
        continue;
      if(map[nowY][nowX]!=map[dice.nowY][dice.nowX])
        continue;
      visited[nowY][nowX] = true;
      num++;
      q.push({nowY, nowX});
    }
  }
  answer += num * map[dice.nowY][dice.nowX];
}

int main(void)
{
  cin >> n >> m >> num;
  vector<vector<int>> map(n+1, vector<int>(m+1, 0));
  for (int i = 1; i <= n;i++){
    for (int j = 1; j <= m;j++)
      cin >> map[i][j];
  }

/* 순서는 다음과 같습니다. 1. 방향으로 출발, 전개도바꾸고 다음 방향 정한다 2. 도착한 좌표에서 몇점인지 DFS */
  while (num--)
  {
    GO(map);
    BFS(map);
  }
  cout << answer;
}