#include<iostream>

using namespace std;
int n[10001];//�׽�Ʈ ���̽��� 10000�� ����
bool num[10001];
int main()
{
	int T;

	cin >> T;
	int temp = 0, M = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> temp;
		if (temp > M)//�ִ� ���� ����
			M = temp;
		n[i] = temp;
	}

	//�ִ� ���������� �Ҽ��� ����
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
		for (int j = 2; j <= n[i] / 2; j++)//�� �Ҽ��� ���̰� ���� ���� ���� ����ϱ� ����
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