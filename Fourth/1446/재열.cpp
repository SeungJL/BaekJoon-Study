#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//점화식
// 어떤 지름길을 거쳤을 때 최솟값 = 지름길 길이 + 어떤 지름길 바로 이전 시점의 최솟값
// 어떤 지름길을 거치지 않았을 때 최솟값 = 바로 이전 지름길 끝점까지 거리 + 바로 이전 지름길 시점의 최솟값
//둘 중 더 작은걸로

struct Shortcut {
	int start;
	int end;
	int value;
	Shortcut(int s, int e, int v) {
		this->start = s;
		this->end = e;
		this->value = v;
	}
	bool operator== (Shortcut other) {		//끝점이 일치하면 일치한다고 한다. (이걸 찾을거기 때문)
		if (this->end == other.end) return true;
		else return false;
	}
};

bool compare(Shortcut& s1, Shortcut& s2) {		//끝점 순서대로 오름차순으로 정렬
	if (s1.end < s2.end) return true;
	else return false;
}

int dp[10001] = {0,};		//어떤 지점까지 가는 최솟값 기록
vector<Shortcut> shortcuts;


int findShortest (int location, int recentShortcutIndex) {
	if (location == 0) return 0;
	if (dp[location] != 0) return dp[location];

//해당 위치로 끝나는 지름길이 있다면?
	vector<int> mins;		//최솟값 후보들


	while (shortcuts[recentShortcutIndex].end > location && recentShortcutIndex > 0) recentShortcutIndex--;
	//후보1. 그 지름길을 거쳤을 때의 최솟값
	//해당 위치로 끝나는 지름길이 여러개일 수도 있으니까
	while (shortcuts[recentShortcutIndex].end == location) {
		mins.push_back(shortcuts[recentShortcutIndex].value + findShortest(shortcuts[recentShortcutIndex].start, recentShortcutIndex - 1));
		recentShortcutIndex--;
	}
	//후보2. 그 지름길을 거치지 않았을 때의 최솟값
	mins.push_back((location - shortcuts[recentShortcutIndex].end) + findShortest(shortcuts[recentShortcutIndex].end, recentShortcutIndex));

	//최솟값선정
	sort(mins.begin(), mins.end());

	return dp[location] = mins[0];
}	

int main() {
	int N, D;
	cin >> N >> D;

	shortcuts.push_back(Shortcut(0,0,0));		//유효한 결과를 위해서?
	for (int i = 0; i < N; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		shortcuts.push_back(Shortcut(s, e, v));
	}
	sort(shortcuts.begin(), shortcuts.end(), compare);

	//역방향으로 탐색
	int recentShortcutIndex = shortcuts.size() - 1;		//가장 최근에 탐색했던 지름길 인덱스 기록되는 변수
	cout << findShortest(D, recentShortcutIndex) << endl;

	return 0;
}
