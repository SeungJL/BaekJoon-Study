#include <iostream>
#include <cstdlib>	
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, x_home, y_home, x_rock, y_rock;
		cin >> n >> x_home >> y_home;
		vector<pair<int,int>> stores(n+1);
		bool is_visited[n];
		stores[0] = make_pair(x_home, y_home);
		for (int j = 1; j <= n; j++) {
			cin >> stores[j].first >> stores[j].second;
			is_visited[j] = false;
		}
		cin >> x_rock >> y_rock;
		queue<int> q;		
		q.push(0);
		is_visited[0] = true;
		bool reached = false;
		while (!q.empty()) {
			int now_idx = q.front();
			q.pop();
			pair<int,int> now_position = stores[now_idx];
			if (abs(x_rock - now_position.first) + abs(y_rock - now_position.second) <= 1000) {
				reached = true;
				break;
			}
			else {
				for (int j = 0; j <= n; j++) {		
					if (!is_visited[j] && abs(now_position.first - stores[j].first) + abs(now_position.second - stores[j].second) <= 1000) {
						q.push(j);
						is_visited[j] = true;
					}
				}
			}
		}
		if (reached) 
			cout << "happy" << endl;
		else
			cout << "sad" << endl;
	}
	return 0;
}
