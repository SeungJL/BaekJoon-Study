#include<iostream>

using namespace std;

int N, C, W;//나무,비용,가격 K개*L길이*W가격-cnt*C
int tree[50];
int cnt, maxN;

int main()
{
	cin >> N >> C >> W;
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
		if (tree[i] > maxN)
			maxN = tree[i];
	}
	int piece, temp;
	long long money, ans = 0;
	for (int i = 1; i <= maxN; i++)//C
	{
		money = 0;
		for (int j = 0; j < N; j++)
		{
			piece = tree[j] / i;
			temp = tree[j] % i;
			if (temp == 0)// 4/2 일 경우(나누어 떨어질 때) 한번만 자른 것
				cnt = piece - 1;
			else
				cnt = piece;// 5/2일 경우 2번 자른 것

			if (piece != 0)// 2/5 일 경우 팔 수 없다.
			{
				/*4 1000 1

				2 1 1 1*/
				if (piece * i * W - cnt * C > 0)//안 자르는 것이 이득일 때(자르면 마이너스가 될때)가 있으므로 나무 하나하나를 자를 때마다 수익이 발생하는지 체크
					money += piece * i * W - cnt * C;
			}
			//if(temp==0)
			//cout << money << endl;

		}
		if (money > ans)
			ans = money;


	}
	cout << ans;

}