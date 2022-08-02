#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, K, result;
bool visit[26];
string str;
string word[50];

void solve(char c, int cnt)
{
	if (cnt == K - 5)
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			bool check = true;
			for (int j = 0; j < word[i].size(); j++)
			{
				if (!visit[word[i][j] - 'a'])
				{
					check = false;
					break;
				}
			}
			if (check) sum++;
		}

		result = max(sum, result);
		return;
	}

	for (int i = c; i < 26; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			solve(i, cnt + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		tmp.erase(0, 4);
		tmp.erase(tmp.size() - 4, tmp.size());
		word[i] = tmp;
	}

	if (K < 5)
	{
		cout << 0 << '\n';
		return 0;
	}

	visit['a' - 'a'] = true;
	visit['n' - 'a'] = true;
	visit['t' - 'a'] = true;
	visit['i' - 'a'] = true;
	visit['c' - 'a'] = true;

	solve(0, 0);

	cout << result << '\n';
}