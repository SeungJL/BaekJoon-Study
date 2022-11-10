#include <bits/stdc++.h>
using namespace std;
int main()
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> result(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	result = v;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
				result[i] = max(result[i], result[j] + v[i]);
		}		
	}

	cout << *max_element(result.begin(), result.end());

}
