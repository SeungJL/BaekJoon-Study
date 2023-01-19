#include<iostream>
#include<vector>

using namespace std;
//���� ���� N�� ���� ���� S, �׸��� M��
int N, S, M;
int num[50];
int a, b;

void nextV(vector<bool>volumeT, int idx)//���� ������ ���
{
	vector<bool> volume(1001); 

	if (idx == N)
	{
		for (int i = 1000; i >= 0; i--)
		{
			if (volumeT[i])
			{
				cout << i;
				exit(0);
			}

		}
		cout << -1;
		exit(0);
	}


	for (int i = 0; i < 1001; i++)
	{
		if (volumeT[i])
		{
			a = i + num[idx];
			b = i - num[idx];
			if (a <= M)
				volume[a] = true;
			if (b >= 0)
				volume[b] = true;

		}
	}
	nextV(volume, idx + 1);//volume�� ����Ǿ� volumeT�� ����
}

int main()
{

	cin >> N >> S >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	vector<bool> volume(1001);//������ �ִ밪�� 1000���� ����
	volume[S] = true;//ó�� ����
	nextV(volume, 0);
}

