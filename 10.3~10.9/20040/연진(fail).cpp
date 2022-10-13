#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{

	int n, m; // 점 개수, 차례수
	cin >> n >> m;
	int *group_num = new int[n + 1];
	for (int i = 0; i <= n; i++)
		group_num[i] = 0;

	int idx = 1;
	int answer;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (group_num[a] == 0 && group_num[b] == 0)
		{
			group_num[a] = idx;
			group_num[b] = idx;
			idx++;
		}
		else if (group_num[a] == group_num[b])
		{ // 사이클 발견
			if (m < i)
				answer = 0;
			else
				answer = i;
			break;
		}
		else if (group_num[a] != 0 && group_num[b] != 0)
		{
			// 통합
			int small_idx = group_num[a] < group_num[b] ? group_num[a] : group_num[b];
			int big_idx = group_num[a] > group_num[b] ? group_num[a] : group_num[b];
			for (int j = 0; j <= n; j++)
			{
				if (group_num[j] == big_idx)
					group_num[j] = small_idx;
			}
		}

		else if (group_num[a] == 0)
		{
			group_num[a] = group_num[b];
		}
		else if (group_num[b] == 0)
		{
			group_num[b] = group_num[a];
		}
	}
	cout << answer;

	return 0;
}