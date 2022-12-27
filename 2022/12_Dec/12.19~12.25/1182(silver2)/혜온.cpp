#include<iostream>
#include<cmath>

using namespace std;
int sum = 0;
int N, S, ans = 0;
int num[20];

void dfs(int sum, int index)
{
	if (index >= N)
		return;
	if (sum + num[index] == S)
		ans++;
	dfs(sum + num[index], index + 1);
	dfs(sum, index + 1);
}

int main()
{

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	dfs(sum, 0);
	cout << ans;



}