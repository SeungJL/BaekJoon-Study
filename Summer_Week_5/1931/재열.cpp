#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> datas;

bool compare(pair<int,int>& p1, pair<int,int>& p2) {
	if (p1.second < p2.second) 
		return true;
	else if (p2.second < p1.second) 
		return false;
	else return p1.first < p2.first;
}

int get_max_value(int start_time, int now_idx) {
	int max_value = 0;
	for (int i = now_idx; i < datas.size(); i++) {	
		if (datas[i].first >= start_time) {		
			max_value = get_max_value(datas[i].second, i+1) + 1;	
			break;
		}
	}
	return max_value;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	int temp1, temp2;
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		datas.push_back(make_pair(temp1, temp2));
	}
	sort(datas.begin(), datas.end(), compare);
	cout << get_max_value(0, 0) << endl;

	return 0;
}
