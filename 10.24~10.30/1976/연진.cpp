#include <iostream>
using namespace std;

int N, M; // 도시 수, 여행할 도시 수
int arr[200][200];
int visited[200] = {
		0,
};
int travel[1000];

void init()
{
	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int k;
			cin >> k;
			arr[i][j] = k;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int k;
		cin >> k;
		travel[i] = k - 1; // 1뺀값을 넣어 인덱스 접근이 쉽게
	}
}

void check_visit(int start)
{
	visited[start] = 1;
	for (int i = 0; i < N; i++)
	{
		if (arr[start][i] == 1 && visited[i] == 0)
		{
			check_visit(i);
		}
	}
}

void get_answer(){

	for (int i = 0; i < M; i++)
	{
		if (visited[travel[i]] == 0)
		{
			cout << "NO";
			return ;
		}
	}
	cout << "YES";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력받기
	init();
	check_visit(travel[0]);
	get_answer();


	return 0;
}