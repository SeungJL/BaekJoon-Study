#include<iostream>

using namespace std;
int n, m, D, Y, X;//세로,가로,방향,y좌표,x좌표
int arr[51][51];
bool visit[51][51];
int r[4];
int b, rt;
bool check = false;
int ans;//로봇청소기가 출력하는 칸의 개수
int answer;
// d가 0:북쪽, 1:동쪽, 2: 남쪽, 3: 서쪽

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };//바라보는 방향으로 1전진
//
void move(int y, int x, int d)
{

	if (!visit[y][x])
	{
		ans++;
		visit[y][x] = true;
	}
	for (int i = 0; i < 4; i++)
	{
		d = r[d];
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] == 1)
			continue;
		if (!arr[ny][nx] && !visit[ny][nx])//빈칸이고 방문한 적이 없다면
		{


			//청소하지 않은 공간이 존재한다면
			//그 방향으로 회전한 다음 한 칸 전진
			move(ny, nx, d);
		}

	}
	//네 방향 모두 청소가 이미 되어있거나 벽인 경우에는 방향을 유지하고 후진
	if (d == 2 || d == 0)
		b = 2 - d;
	else
		b = 4 - d;

	if (!arr[y + dy[b]][x + dx[b]])//후진 한 곳이 벽이 아니라면
	{
		move(y + dy[b], x + dx[b], d);
	}
	cout << ans << endl;
	exit(0);
}

int main()
{
	cin >> n >> m;
	cin >> Y >> X >> D;

	//왼쪽으로 회전
	r[0] = 3;
	r[1] = 0;
	r[2] = 1;
	r[3] = 2;
	

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	move(Y, X, D);

}