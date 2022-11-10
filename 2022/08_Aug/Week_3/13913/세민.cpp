#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

constexpr int MAX = 100001;	//0<=N,K<=100,000
int N, K;
int T = 987654321;	//시간
bool visited[MAX];	//방문 여부 저장
int p[MAX];	//해당 위치 직전의 위치 저장
vector<int> v;	//경로
queue<pair<int, int>> q;	//위치, 시간

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	q.push(make_pair(N, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int n = q.front().second;
		q.pop();

		if (T < n) break;
		if (x == K) {
			T = n;
			int idx = x;
			while (idx != N) {
				v.push_back(idx);
				idx = p[idx];
			}
			v.push_back(N);
			continue;
		}

		if (x - 1 >= 0 && !visited[x - 1]) {
			q.push(make_pair(x - 1, n + 1));
			visited[x - 1] = true;
			p[x - 1] = x;
		}
		if (x + 1 <= 100000 && !visited[x + 1]) {
			q.push(make_pair(x + 1, n + 1));
			visited[x + 1] = true;
			p[x + 1] = x;
		}
		if (x * 2 <= 100000 && !visited[x * 2]) {
			q.push(make_pair(x * 2, n + 1));
			visited[x * 2] = true;
			p[x * 2] = x;
		}
	}

	cout << T << '\n';
	for (int i = v.size() - 1; i >= 0; --i) {
		cout << v[i] << " ";
	}
	return 0;
}