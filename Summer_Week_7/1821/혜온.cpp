#include<iostream>

using namespace std;
int num[11];
int N, F;
long long arr[11][11];
int visit[11];
bool ans;

bool chk()
{
	int sizeN = N;
	int i = 1;

	/*while(sizeN>0)
	{
		for(int j=1;j<sizeN;j++)
			arr[j] = arr[j] + arr[j + 1];
		sizeN--;
	}*/
	for (int i = 1; i <= N; i++)arr[1][i] = num[i];
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N - i + 1; j++)
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j + 1];
	}
	

	if (arr[N][1] == F)
	{
		for (int j = 1; j <= N; j++)
			cout << num[j] << " ";

		return true;
	}
	else
		return false;

}

void backtracking(int depth)
{
	if (ans)
		return;
	if (depth == N + 1)
	{

		if (chk())
		{
			ans = true;
		}
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			num[depth] = i;
			backtracking(depth + 1);
			num[depth] = 0;
			visit[i] = false;
		}
	}
}



int main()
{
	cin >> N >> F;
	backtracking(1);
}