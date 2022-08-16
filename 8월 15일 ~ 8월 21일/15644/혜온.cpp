#include<iostream>
#include<algorithm>


using namespace std;

int num[9];
int N, M;
int arr[8];


void backtracking(int depth, int index)
{
	if (depth == M)
	{



		for (int i = 0; i < M; i++)
		{

			cout << arr[i] << " ";
		}

		cout << endl;

		return;
	}

	for (int i = index; i < N; i++)
	{

		if (num[i] == num[i - 1] && i != index)continue;
		arr[depth] = num[i];
		backtracking(depth + 1, i + 1);


	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);

	backtracking(0, 0);
}