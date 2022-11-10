#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int>& p1, pair<int,int>& p2) {
	if (p1.first > p2.first) 
		return true;
	else if (p1.first < p2.first) 
		return false;
	else {		
		return p1.second < p2.second;
	}
}

int main() {
	int N;
	cin >> N;

	vector<pair<int,int>> korean;		//{점수, 학생번호}
	vector<pair<int,int>> english;
	vector<pair<int,int>> math;
	vector<pair<int,int>> science;
	bool alreadyGet[N+1];

	for (int i = 0; i < N; i++) {
		int num, k, e, m, s;
		cin >> num >> k >> e >> m >> s;
		korean.push_back({k, num});
		english.push_back({e, num});
		math.push_back({m, num});
		science.push_back({s, num});
	}

	fill(alreadyGet, alreadyGet+N+1, false);

	sort(korean.begin(), korean.end(), compare);
	sort(english.begin(), english.end(), compare);
	sort(math.begin(), math.end(), compare);
	sort(science.begin(), science.end(), compare);

	cout << korean[0].second << ' ';
	alreadyGet[korean[0].second] = true;

	int i = 0;
	while (alreadyGet[english[i].second])
		i++;
	cout << english[i].second << ' ';
	alreadyGet[english[i].second] = true;

	i = 0;
	while (alreadyGet[math[i].second])
		i++;
	cout << math[i].second << ' ';
	alreadyGet[math[i].second] = true;

	i = 0;
	while (alreadyGet[science[i].second])
		i++;
	cout << science[i].second << endl;

	return 0;
}