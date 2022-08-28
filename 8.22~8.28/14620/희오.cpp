#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int y, x;
	Point(int _y, int _x) : y(_y), x(_x) {}
};

struct PlantingSpot {
	Point loc;
	int cost;
	PlantingSpot(Point _l, int _c) : loc(_l), cost(_c) {}
	bool operator< (const PlantingSpot& x) const {
		return (cost < x.cost);
	}
};

int N;
int map[10][10] = {};
vector<PlantingSpot> spot_arr;
int ch[10][10] = {};
int total_cost = 0;
int res = 10000000;

int YY[13] = {0, -1, 0, 1, 0, -2, -1, 0, 1, 2, 1, 0, -1};
int XX[13] = {0, 0, 1, 0, -1, 0, 1, 2, 1, 0, -1, -2, -1};

void dfs_comb(int depth, int last_i) {
	if (depth > 3) {
		if (total_cost < res) res = total_cost;
		return ;
	}

	for (int i=last_i+1; i<spot_arr.size(); i++) {
		int cur_y = spot_arr[i].loc.y;
		int cur_x = spot_arr[i].loc.x;
		if (ch[cur_y][cur_x] == 0) {
			for (int d=0; d<13; d++) {
				if (cur_y + YY[d] >= 0 && cur_y + YY[d] < N && cur_x + XX[d] >= 0 && cur_x + XX[d] < N) 
					ch[cur_y + YY[d]][cur_x + XX[d]] += depth;
			}
			total_cost += spot_arr[i].cost;
			dfs_comb(depth + 1, i);
			for (int d=0; d<13; d++) {
				if (cur_y + YY[d] >= 0 && cur_y + YY[d] < N && cur_x + XX[d] >= 0 && cur_x + XX[d] < N) 
					ch[cur_y + YY[d]][cur_x + XX[d]] -= depth;
			}
			total_cost -= spot_arr[i].cost;	
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	cin >> N;

	for(int y=0; y<N; y++) {
		for(int x=0; x<N; x++) {
			cin >> map[y][x];
		}
	}

	for(int y=1; y<N-1; y++) {
		for(int x=1; x<N-1; x++) {
			int c = 0;
			for(int d=0; d<5; d++) c += map[y + YY[d]][x + XX[d]];
			spot_arr.push_back(PlantingSpot(Point(y, x), c));
		}
	}

	dfs_comb(1, -1);
	cout << res << "\n";
}