#include<iostream>

using namespace std;
int n, m, D, Y, X;//����,����,����,y��ǥ,x��ǥ
int arr[51][51];
bool visit[51][51];
int r[4];
int b, rt;
bool check = false;
int ans;//�κ�û�ұⰡ ����ϴ� ĭ�� ����
int answer;
// d�� 0:����, 1:����, 2: ����, 3: ����

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };//�ٶ󺸴� �������� 1����
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
		if (!arr[ny][nx] && !visit[ny][nx])//��ĭ�̰� �湮�� ���� ���ٸ�
		{


			//û������ ���� ������ �����Ѵٸ�
			//�� �������� ȸ���� ���� �� ĭ ����
			move(ny, nx, d);
		}

	}
	//�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡�� ������ �����ϰ� ����
	if (d == 2 || d == 0)
		b = 2 - d;
	else
		b = 4 - d;

	if (!arr[y + dy[b]][x + dx[b]])//���� �� ���� ���� �ƴ϶��
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

	//�������� ȸ��
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