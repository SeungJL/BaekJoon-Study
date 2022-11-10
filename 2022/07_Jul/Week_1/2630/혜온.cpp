#include<iostream>

using namespace std;
int n;
int paper[129][129];
int blue, white;

void division(int y, int x, int N)
{

	int cnt = 0;
	for (int i = y; i < y + N; i++)
		for (int j = x; j < x + N; j++)
			if (paper[i][j])
				cnt++;
	if (!cnt)	//다 0이면
		white++;
	else if (cnt == (N * N))//다 1이면
		blue++;
	else
	{

		division(y, x, N / 2);
		division(y, x + N / 2, N / 2);
		division(y + N / 2, x, N / 2);
		division(y + N / 2, x + N / 2, N / 2);

	}

}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> paper[i][j];

	division(1, 1, n);
	cout << white << "\n" << blue;
}