#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

constexpr int MAX = 1001;	//순열의 최대 크기 : 1000

int arr[MAX];
bool visited[MAX];

bool is_cycle(int from)
{
	visited[from] = true;
	if (visited[arr[from]]) return true;	//이미 방문한 노드를 재방문하는 경우 사이클이 존재
	return is_cycle(arr[from]);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("input.txt", "r", stdin);

	int T;	//테스트 케이스의 개수
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			int num;
			cin >> num;
			arr[i] = num;
			visited[i] = false;
		}

		int ans = 0;	//순열 사이클의 개수
		for (int i = 1; i <= N; ++i) {
			if (!visited[i]) {
				if (is_cycle(i)) ans++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}