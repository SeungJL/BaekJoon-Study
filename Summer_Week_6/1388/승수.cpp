#include <bits/stdc++.h>
using namespace std;
int main()
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	int n, m;
	int c = 0;
	string s[105];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '-')
			{
				if (j == m - 1 || s[i][j + 1] == '|')
					c++;
			}
			if (s[i][j] == '|')
			{
				if (i == n - 1 || s[i + 1][j] == '-')
					c++;
			}
		}
	}
	cout << c;
	
}
