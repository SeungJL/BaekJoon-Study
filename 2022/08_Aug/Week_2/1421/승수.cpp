#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, c, w;
	cin >> n >> c >> w;
	int max = 0;
	vector<int> tree(n);

	for (int i = 0; i < n; i++)
	{
		cin >> tree[i];
		if (max < tree[i])
			max = tree[i];
	}

	long long result = 0;
	for (int i = 1; i <= max; i++)
	{
		long long sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (tree[j] < i) // 예외처리 : 길이보다 나무가 작으면 연산X
				continue;
			else
			{
				int piece, div;
				piece = tree[j] / i;
				if (tree[j] % i == 0)
					div = piece - 1;
				else
					div = piece;

				long long cal = piece * i * w - div * c;
				if (cal > 0)
					sum += cal;

			}
		}
		if (result < sum)
			result = sum;
	}
	cout << result;
	
	return 0;
}
