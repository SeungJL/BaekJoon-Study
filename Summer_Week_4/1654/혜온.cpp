#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int K, N;
	int kk[10000] = { 0 };

	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> kk[i];
	}

	long long low = 0, high = pow(2, 31) - 1;
	long long m;
	while (low <= high)
	{
		m = (low + high) / 2;
		int i = 0;
		long long cnt = 0;
		while (i < K)
		{
			cnt += kk[i] / m;
			i++;
			//cout << m << "   " << cnt << endl;
		}
		if (cnt < N)
		{
			high = m - 1;
			//cout << high-1<< endl;
		}
		else
		{
			low = m + 1;
		}

	}
	cout << high;
}