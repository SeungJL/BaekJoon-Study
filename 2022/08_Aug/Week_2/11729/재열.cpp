#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int,int>> moved;
int counts = 0;

void move(int from, int to, int target) {
	if (target == 1) {		
		moved.push_back(make_pair(from, to));
		counts++;
	}
	else {
		int temp = 6 - from - to;
		move(from, temp, target-1);
		moved.push_back(make_pair(from, to));
		counts++;
		move(temp, to, target-1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N;
	move(1, 3, N);
	cout << counts << '\n';
	for (int i = 0; i < moved.size(); i++) 
		cout << moved[i].first << ' ' << moved[i].second << '\n';
	return 0;
}
