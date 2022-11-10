#include<iostream>

using namespace std;
int num[100002];
int sum[100002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, i, j;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
		sum[i] = sum[i - 1] + num[i];
	}
	while (M--)
	{
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << "\n";
	}

}