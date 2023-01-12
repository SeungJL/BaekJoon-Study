#include<iostream>

using namespace std;
int n[10001];//테스트 케이스가 10000개 이하
bool num[10001];
int main()
{
	int T;

	cin >> T;
	int temp = 0, M = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> temp;
		if (temp > M)//최대 수를 구함
			M = temp;
		n[i] = temp;
	}

	//최대 범위까지만 소수를 구함
	for (int i = 2; i < M; i++)
	{
		if (!num[i])
		{
			for (int j = i * 2; j < M; j += i)//2 4 6   3 6 9
			{
				num[j] = true;

			}
		}

	}
	int ansA = 0, ansB = 0;
	for (int i = 0; i < T; i++)//3 5  8
	{
		for (int j = 2; j <= n[i] / 2; j++)//두 소수의 차이가 가장 작은 것을 출력하기 위해
		{
			if (!num[j] && !num[n[i] - j])
			{

				ansA = j;
				ansB = n[i] - j;
			}
		}
		cout << ansA << " " << ansB << endl;
	}
}