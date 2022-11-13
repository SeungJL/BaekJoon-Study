#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Road {
	int house_A, house_B;
	int cost;

	Road(int a, int b, int c) : house_A(a), house_B(b), cost(c) {};
	bool operator<(const Road &x) const {
		return (cost < x.cost);
	}
};

vector<int> set_num; // 각 집이 포함된 마을 번호

int my_find(int x) {
	if (set_num[x] == x) return x;
	else return set_num[x] = my_find(set_num[x]);
}

void my_union(int a, int b) {
	int pa = my_find(a);
	int pb = my_find(b);
	(pa < pb) ? set_num[pb] = pa : set_num[pa] = pb;
}

bool is_same_set(int a, int b) {
	return (my_find(a) == my_find(b));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int N, M;
	int a, b, c;
	vector<Road> roads;

	/* input */
	cin >> N >> M;	
	while (M--) {
		cin >> a >> b >> c;
		roads.push_back(Road(a, b, c));
	}

	/* solve */
	sort(roads.begin(), roads.end()); // 길을 유지비 기준 오름차순 정렬

	for (int i=0; i<=N; i++) set_num.push_back(i);
	int set_cnt = N, cost_sum = 0; // set_cnt: 마을의 개수, cost_sum: 길 유지비

	for (auto e : roads) {
		if (set_cnt <= 2) 
			break;

		a = e.house_A;
		b = e.house_B;
		c = e.cost;

		// 이미 같은 마을에 포함되어 있는 경우
		if (is_same_set(a, b)) 
			continue;
		// 같은 마을에 포함되어 있지 않은 경우
		my_union(a, b);
		set_cnt--;
		cost_sum += c;
	}

	cout << cost_sum << "\n";

}