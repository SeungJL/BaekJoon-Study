#include<iostream>
#include<cstring>

using namespace std;



int t;
int ability[11][11];
int ans;
int num = 11;
bool check[11];
void selection(int n, int sum)
{
	if (n == num)
	{
		if (sum > ans)
			ans = sum;
		return;
	}
	for (int i = n; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (ability[i][j] != 0 && !check[j])
			{
				check[j] = true;
				sum += ability[i][j];
				selection(i + 1, sum);
				sum -= ability[i][j];;
				check[j] = false;
			}
		}
		return;

	}


}
int main()
{
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
			{
				cin >> ability[i][j];
			}
		selection(0, 0);
		cout << ans << endl;
		memset(ability, 0, sizeof(ability));
		memset(check, 0, sizeof(check));

		ans = 0;

	}
}