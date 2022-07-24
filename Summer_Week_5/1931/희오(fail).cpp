// BOJ 1931

#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

#define sp first 
#define ep second 

vector<pair<int, int>> meetings;
int res, max_sp;

void DFS(vector<pair<int, int>>::iterator cur, int cnt) {
	for (auto m = cur + 1; m != meetings.end(); m++) {
		if (cur->ep > max_sp) break;
		if (m->sp < cur->ep) continue;
		DFS(m, cnt+1);
	}
	if (cnt > res) 
		res = cnt;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int N;

	cin >> N;
	meetings.push_back(make_pair(-1, -1));
    max_sp = -1;
	while (N--) {
		int s, e;
		cin >> s >> e;
		meetings.push_back(make_pair(s, e));
        if (s > max_sp) max_sp = s;
	}

	sort(meetings.begin(), meetings.end(),
		[](pair<int, int> const a, pair<int, int> const b) ->bool {
			if (a.sp == b.sp) return (a.ep < b.ep);
			return (a.sp < b.sp);
		});

	res = 0;
	DFS(meetings.begin(), 0);
	cout << res << "\n";
	
}