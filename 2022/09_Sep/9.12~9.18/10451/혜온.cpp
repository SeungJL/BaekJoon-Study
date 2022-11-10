#include<iostream>
#include<cstring>
using namespace std;

int T, n, ans;
int num[1001];
bool visit[1001];
int main()
{
	cin >> T;
	while (T--)
	{
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> num[i];

		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
			{
				while (!visit[i])
				{
					visit[i] = true;
					i = num[i];
				}
				ans++;
			}


		}
		memset(visit, false, sizeof(visit));
		cout << ans << endl;
	}
}