#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	priority_queue<pair<int,int>> pq;		//pair는 {점수, 문제번호} 

	for (int i = 0; i < 8; i++) {
		int n;
		cin >> n;
		pq.push({n, i+1});
	}
	
	int sum = 0;
	vector<int> indexs;
	for (int i = 0; i < 5; i++) {
		sum += pq.top().first;		
		indexs.push_back(pq.top().second);	
		pq.pop();
	}

	sort(indexs.begin(), indexs.end());		
	cout << sum << endl;
	for (auto n : indexs) {
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}
