#include <iostream>
#include <vector>

using namespace std;

int N, M, sum;
int num[100001] = {};
int Sum[100001] = {};
vector<pair<int, int>> cmd;

int main(void)
{
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		Sum[i] = Sum[i - 1] + num[i];
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cmd.push_back(make_pair(a, b));
	}
	
	for (int i = 0; i < M; i++) {
		int start = cmd[i].first;
		int end = cmd[i].second;

		cout << Sum[end] - Sum[start - 1] << '\n';
	}

	return 0;
}