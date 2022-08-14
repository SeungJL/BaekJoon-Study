#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::ios::sync_with_stdio(false);

	int test_case;
	int x1, y1, x2, y2, r1, r2;
	cin >> test_case;
	while (test_case--)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int result = 0;
		double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		
		int c = r1 + r2;

		int small_r = r1 > r2 ? r2 : r1;
		int big_r = r1 < r2 ? r2 : r1;

		if (d > c)
			result = 0;
		else if (d == c)
			result = 1;
		else if (d < c)
		{
			if (r1 == r2 && x1 == x2 && y1 == y2)
				result = -1;
			else if (d + small_r > big_r)
				result = 2;
			else if (d + small_r == big_r)
				result = 1;
			else if (d + small_r < big_r)
				result = 0;
		}
		cout << result << '\n';
	}

	return 0;
}
