#include <bits/stdc++.h>
using namespace std;

void hannoi(int start,int mid, int end, int n)
{
	if (n == 1)
	{
		cout << start << ' ' << end << '\n';
	}
		
	else
	{
		hannoi(start, end, mid, n - 1);
		cout << start << ' ' << end << '\n';
		hannoi(mid, start, end, n - 1);
	}
}


int main()
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	int k;
	cin >> k;

	int number = (int)(pow(2.0, k) - 1);
	cout << number << '\n';
	hannoi(1, 2, 3, k);
	return 0;
}
