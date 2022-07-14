#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct pos {
	int x, y;
};

pos h, f;
vector<pos> c;
vector<int> visit;
int n;

int calc(pos a, pos b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

bool bfs() {
	queue <pos> q;
	q.push(h);

	while (!q.empty()) {
		pos now = q.front();
		q.pop();

		if (calc(f, now) <= 1000) return true;

		for (int i = 0; i < n; i++) {
			pos to = c[i];
			if (visit[i]) continue;
			if (calc(now, to) > 1000) continue;

			visit[i] = 1;
			q.push(c[i]);
		}
	}
	return false;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		c = vector<pos>(n, { 0,0 });
		visit = vector<int>(n, 0);
		cin >> h.x >> h.y;
		for (int i = 0; i < n; i++) {
			cin >> c[i].x >> c[i].y;
		}
		cin >> f.x >> f.y;
		if (bfs()) cout << "happy\n";
		else cout << "sad\n";
	}

	return 0;
}