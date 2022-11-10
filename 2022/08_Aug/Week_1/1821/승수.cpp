#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, f;
	cin >> n >> f;

	vector<int> v;
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	do 
	{
		int arr[10][10];
		int index = 0;
		for (auto i = v.begin(); i != v.end(); i++)
		{
			arr[0][index] = *i;
			index++;
		}
		for (int j = 1; j < n; j++)
		{
			for (int i = 0; i < n - j; i++)
			{
				arr[j][i] = arr[j - 1][i] + arr[j - 1][i + 1];
			}
		}
		if (arr[n - 1][0] == f)
		{
			for (int t = 0; t < n; t++)
			{
				cout << arr[0][t] << ' ';
			}
			break;
		}
	} while (next_permutation(v.begin(), v.end()));

	
	return 0;

}
