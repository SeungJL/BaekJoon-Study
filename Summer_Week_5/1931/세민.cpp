#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int N, begin, end;
	cin >> N;

	vector<pair<int, int>> v;
	
	for (int i = 0; i < N; i++) {
		cin >> begin >> end;
		v.push_back(make_pair(end, begin));
	}

	sort(v.begin(), v.end());

	int time = v[0].first;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (time <= v[i].second) {
			cnt++;
			time = v[i].first;
		}
	}

	cout << cnt;

	return 0;
}