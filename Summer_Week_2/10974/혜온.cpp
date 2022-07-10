#include<iostream>

using namespace std;

int N;
int num[9];
bool check[9];

void backtracking(int depth)
{
	if (depth == N)
	{
		for (int i = 0; i < N; i++)
			cout << num[i] + 1 << ' ';
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++)
	{

		if (!check[i])
		{
			check[i] = true;
			num[depth] = i;
			backtracking(depth + 1);
			check[i] = false;
		}

	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	backtracking(0);
}