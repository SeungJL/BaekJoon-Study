#include<iostream>
#include<cmath>

using namespace std;



int main()
{
	int T;
	int M, N, x, y, delta;
	bool find;
	cin >> T;

	int num = 0;
	while (T--)
	{
		find = false;
		cin >> M >> N >> x >> y;

		if (x > y)
		{
			delta = x - y;
			for (int i = 0; i < N; i++)
			{
				if ((M * i + delta) % N == 0)
				{
					cout << M * i + x << endl;
					find = true;
					break;
				}
			}

		}
		else
		{
			delta = y - x;

			for (int i = 0; i < M; i++)
			{
				if ((N * i + delta) % M == 0)
				{
					cout << N * i + y << endl;
					find = true;
					break;
				}
			}
		}

		if (!find)
			cout << "-1" << "\n";

	}

}

