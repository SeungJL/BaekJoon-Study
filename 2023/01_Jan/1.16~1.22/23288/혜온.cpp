#include<iostream>
#include<string>
#include<cstring>
using namespace std;
//east west south north
struct Dice
{
	int east;//��
	int west;//��
	int south;//��
	int north;//��
	int tos;//��
	int idx;//�Ʒ�
};
Dice dice = { 3,4,5,2,1,6 };
int N, M, K;
int map[22][22];
int  ans;
int score[22][22];
int visit[22][22];
int d = 0;//0: ��, 1:��, 2 :��, 3:��  /  �ݽð� : +1, �ð� : -1 
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
void rotate(int r)//0 �ð����, 1 �ݽð����
{

	if (r)//�ݽð�
	{
		//	cout << "�ݽð� ���� ȸ��" << endl;
		//�ֻ����� ȸ���� �ʿ䰡 ������. �̵����⸸ ȸ�����ָ� ��
			/*tmmp = dice.east;
			dice.east = dice.south;
			dice.south = dice.west;
			dice.west = dice.north;
			dice.north = tmmp;*/
		d++;
	}
	else
	{
		//	cout << "�ð� ���� ȸ��" << endl;

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

bool roll(int direction, int& y, int& x)//�������� 
{

	if (d == 0)//0: ��, 1:��, 2 :��, 3:��
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
		if (x - 1 <= 0)//��ȣ ����
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

	//�ֻ����� ������ ĭ(x, y)�� ���� ������ ȹ���Ѵ�.
	ans += score[y][x];	//�̸� ���ص� ���� ���ϱ�
	//ȸ���� ���� ���ؼ� ȸ���ϱ�
	A = dice.idx; B = map[y][x];
	
	if (A > B)//�ð�������� ȸ��
	{
		
		rotate(0);
		
	}
	else if (A < B)//�� �ð�������� ȸ��
	{

		rotate(1);
	}

	return true;
}

void dfs(int i, int j)//���� ���ϱ�
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
	//dfs �̸� �س��� ���� ���س���
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{

			
			//bfs�� �ٲٴ� ���� �� ȿ����
			dfs(i, j);
			
			score[i][j] = map[i][j] * cnt; //������ B�� C�� ����
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
			//�̵� �������� �� ĭ ��������. ����, �̵� ���⿡ ĭ�� ���ٸ�, �̵� ������ �ݴ�� �� ���� �� ĭ ��������.
			roll(d, y, x);
		}
		

	}
	cout << ans;
}

