#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define name first
#define info_list second

// 고릴라가 k개의 정보를 얻음 (쿼리 1)
void get_info(vector<int> &info_cost, int k) {
	int cost;
	while (k--) {
		cin >> cost;
		info_cost.push_back(cost);
	}
}

// 고릴라가 호석이에게 가장 비싼 b개의 정보를 판매 (쿼리 2) 
// 호석이가 얻은 정보의 가치 합을 리턴
int sell_info(vector<int> &info_cost, int b) {
	int ret = 0;
	sort(info_cost.begin(), info_cost.end());
	while (b-- && !info_cost.empty()) {
		ret += info_cost.back(); info_cost.pop_back();
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	int Q, query, cnt;
	string name;
	map<string, vector<int>> gorillas;  // 정보를 가진 고릴라 리스트 
	long long answer = 0;               // 호석이가 가진 정보의 가치 총합 

	cin >> Q;
	while (Q--) {
		cin >> query >> name >> cnt;
		auto it = gorillas.find(name);  // 고릴라 리스트에 [name]과 동일한 고릴라가 있는지 탐색 
		switch (query) {	
			case (1): // gorilla gets some info
				if (it == gorillas.end()) { // 고릴라 리스트에 [name] 고릴라가 없으면 리스트에 새로 추가 
					vector<int> tmp;
					it = (gorillas.insert(make_pair(name, tmp))).first;
				}
				get_info(it->info_list, cnt);
				break;
			case (2): // HS buys info
				if (it != gorillas.end())   // 고릴라 리스트에 [name] 고릴라가 있을 경우에만 정보 구매 
					answer += sell_info(it->info_list, cnt);
				break;
		}
	}
	cout << answer << "\n";
}