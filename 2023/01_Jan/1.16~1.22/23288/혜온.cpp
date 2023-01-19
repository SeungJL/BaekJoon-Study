#include<iostream>
#include<string>
#include<cstring>
using namespace std;
//east west south north
struct Dice
{
	int east;//동
	int west;//서
	int south;//남
	int north;//북
	int tos;//위
	int idx;//아래
};
Dice dice = { 3,4,5,2,1,6 };
int N, M, K;
int map[22][22];
int  ans;
int score[22][22];
int visit[22][22];
int d = 0;//0: 동, 1:북, 2 :서, 3:남  /  반시계 : +1, 시계 : -1 
int A, B;
int cnt;
void changeDice()
{
	int tmp = 0;

	if (d == 0)
	{
		tmp = dice.idx;
		dice.idx = dice.east;
		dice.east = dice.tos;
		dice.tos = dice.west;
		dice.west = tmp;;


	}
	else if (d == 1)
	{
		tmp = dice.tos;
		dice.tos = dice.south;
		dice.south = dice.idx;
		dice.idx = dice.north;
		dice.north = tmp;
	}
	else if (d == 2)
	{
		tmp = dice.tos;
		dice.tos = dice.east;
		dice.east = dice.idx;
		dice.idx = dice.west;
		dice.west = tmp;;
	}
	else if (d == 3)
	{

		tmp = dice.tos;
		dice.tos = dice.north;
		dice.north = dice.idx;
		dice.idx = dice.south;
		dice.south = tmp;
	}
}
void rotate(int r)//0 시계방향, 1 반시계방향
{

	if (r)//반시계
	{
		//	cout << "반시계 방향 회전" << endl;
		//주사위를 회전할 필요가 없었다. 이동방향만 회전해주면 됨
			/*tmmp = dice.east;
			dice.east = dice.south;
			dice.south = dice.west;
			dice.west = dice.north;
			dice.north = tmmp;*/
		d++;
	}
	else
	{
		//	cout << "시계 방향 회전" << endl;

			/*tmmp = dice.east;
			dice.east = dice.north;
			dice.north= dice.west;
			dice.west = dice.south;
			dice.south= tmmp;*/
		d--;
	}
	if (d == 4)
		d = 0;
	else if (d == -1)
		d = 3;

}

bool roll(int direction, int& y, int& x)//동서남북 
{

	if (d == 0)//0: 동, 1:북, 2 :서, 3:남
	{
		if (x + 1 > M)
		{
			d = 2 - d;
			return false;
		}
		x++;
	}
	else if (d == 2)
	{
		if (x - 1 <= 0)//등호 조심
		{
			d = 2 - d;
			return false;
		}
		x--;
	}
	else if (d == 1)
	{
		if (y - 1 <= 0)
		{
			d = 4 - d;
			return false;
		}
		y--;
	}
	else
	{
		if (y + 1 > N)
		{
			d = 4 - d;
			return false;
		}
		y++;
	}

	changeDice();

	//주사위가 도착한 칸(x, y)에 대한 점수를 획득한다.
	ans += score[y][x];	//미리 구해둔 점수 더하기
	//회전할 방향 구해서 회전하기
	A = dice.idx; B = map[y][x];
	
	if (A > B)//시계방향으로 회전
	{
		
		rotate(0);
		
	}
	else if (A < B)//반 시계방향으로 회전
	{

		rotate(1);
	}

	return true;
}

void dfs(int i, int j)//점수 구하기
{
	cnt++;
	visit[i][j] = true;
	int dy[] = { 1,0,-1,0 };
	int dx[] = { 0,-1,0,1 };
	for (int k = 0; k < 4; k++)
	{
		int y = i + dy[k];
		int x = j + dx[k];
		if (y <= 0 || y > N || x <= 0 || x > M)
			continue;
		if (!visit[y][x] && map[i][j] == map[y][x])
		{

			dfs(y, x);
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	int y = 1, x = 1;
	//dfs 미리 해놔서 점수 구해놓기
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{

			
			//bfs로 바꾸는 것이 더 효율적
			dfs(i, j);
			
			score[i][j] = map[i][j] * cnt; //점수는 B와 C를 곱함
			cnt = 0;
			memset(visit, false, sizeof(visit));
			//	}
				/*if (map[i][j] == map[i + 1][j])
				{
					score[i + 1][j] = score[i][j];
					visit[i + 1][j] = true;
				}
				if (map[i][j] == map[i ][j+1])
				{
					score[i ][j+1] = score[i][j];
					visit[i ][j+1] = true;
				}*/
				/*if (map[i][j] == map[i][j - 1])
				{
					score[i][j + 1] = score[i][j];
					visit[i][j + 1] = true;
				}*/
		}
	
	while (K--)
	{
		if (!roll(d, y, x))
		{
			//이동 방향으로 한 칸 굴러간다. 만약, 이동 방향에 칸이 없다면, 이동 방향을 반대로 한 다음 한 칸 굴러간다.
			roll(d, y, x);
		}
		

	}
	cout << ans;
}

