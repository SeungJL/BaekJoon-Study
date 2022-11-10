#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int A, B;
bool visit[10000];

void bfs()
{
	queue<pair<int, string>> q;
	q.push(make_pair(A, ""));
	visit[A] = true;

	while (!q.empty()) {
		int x = q.front().first;
		string y = q.front().second;

		q.pop();

		if (x == B) {
			cout << y << '\n';
			break;
		}

		int next;
		
		next = (x * 2) % 10000;
		if (!visit[next]) {
			visit[next] = true;
			q.push(make_pair(next, y + "D"));
		}

		next = (x - 1) < 0 ? 9999 : x - 1;
		if (!visit[next]) {
			visit[next] = true;
			q.push(make_pair(next, y + "S"));
		}

		next = (x % 1000) * 10 + (x / 1000);
		if (!visit[next]) {
			visit[next] = true;
			q.push(make_pair(next, y + "L"));
		}

		next = (x % 10) * 1000 + (x / 10);
		if (!visit[next]) {
			visit[next] = true;
			q.push(make_pair(next, y + "R"));
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		memset(visit, false, sizeof(visit));	//방문 여부 저장하는 배열 초기화
		cin >> A >> B;
		bfs();
	}

	return 0;
}