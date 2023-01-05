#include<iostream>

using namespace std;

int N;
int matrix[1025][1025];
int half;
//void pooling(int n,int y,int x)
//{
//	if (n == 2)
//	{
//
//	}
//	else
//	{
//		half = n / 2;
//		pooling(n / 2, y, x);
//		pooling(n / 2, y, x + half);
//		pooling(n / 2, y + half, x);
//		pooling(n / 2, y + half, x + half);
//
//	}
//}
void pooling(int y, int x)
{
	int max = -100000;//matrix[y][x];
	int second = max;
	for (int i = y; i < y + 2; i++)
		for (int j = x; j < x + 2; j++)
		{

			if (matrix[i][j] > max)
			{
				second = max;
				max = matrix[i][j];

			}
			else
			{
				if (matrix[i][j] > second)
					second = matrix[i][j];
			}
		}

	matrix[y / 2][x / 2] = second;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];

	while (N)
	{
		for (int i = 0; i < N; i += 2)
			for (int j = 0; j < N; j += 2)
			{

				pooling(i, j);
			}
		N /= 2;

	}
	cout << matrix[0][0];
}