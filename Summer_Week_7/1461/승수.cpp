#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	int sum = 0;
	cin >> n >> m;
	int zero_index = 0;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
			zero_index++;
		else
			break;
	}

	for (int i = 0; i < zero_index; i += m)
	{
		sum += abs(arr[i] * 2);
	}
	for (int i = n - 1; i >= zero_index; i -= m) 
	{
		sum += (arr[i] * 2);
	}

	
	sum -= max(abs(arr[0]), abs(arr[n - 1]));
	
	cout << sum;
	return 0;

}
