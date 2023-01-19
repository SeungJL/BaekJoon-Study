#include<iostream>
#include<vector>

using namespace std;
//곡의 개수 N과 시작 볼륨 S, 그리고 M이
int N, S, M;
int num[50];
int a, b;

void nextV(vector<bool>volumeT, int idx)//다음 볼륨을 계산
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
	nextV(volume, idx + 1);//volume이 복사되어 volumeT에 전달
}

int main()
{

	cin >> N >> S >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	vector<bool> volume(1001);//볼륨의 최대값은 1000까지 가능
	volume[S] = true;//처음 볼륨
	nextV(volume, 0);
}

