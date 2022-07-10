#include<iostream>

using namespace std;

int N;

int tile[31];
int main()
{
	cin >> N;
	if (N % 2 == 1)
	{
		cout << 0;
		return 0;
	}
	tile[0] = 1;
	tile[2] = 3;

	for (int i = 4; i <= N; i += 2)
	{
		tile[i] = tile[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2)
		{
			tile[i] += tile[j] * 2;
		}

	}
	cout << tile[N];


}