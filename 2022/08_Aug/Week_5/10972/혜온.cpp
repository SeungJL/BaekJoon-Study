#include<iostream>
#include<algorithm>

using namespace std;

int n;
int num[10000];

bool check;



int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)//54321
	{
		cin >> num[i];
		if (i > 0 && num[i] > num[i - 1])
			check = true;
	}
	if (!check)
	{
		cout << "-1";
		return 0;
	}

	int k;
	for (k = n - 1; k > 0; k--)// 1 2 3 4
	{
		if (num[k - 1] < num[k])
			break;
	}

	for (int j = n - 1; j >= k; j--)
	{

		if (num[j] > num[k - 1])
		{

			swap(num[j], num[k - 1]);
			sort(num + k, num + n);
			for (int i = 0; i < n; i++)
			{
				cout << num[i] << " ";
			}
			return 0;
		}
	}




	for (int i = 0; i < n; i++)
	{
		cout << num[i] << " ";
	}
}