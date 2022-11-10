// 20055

#include <iostream>
#include <deque>

using namespace std;

int N, K;
int *belt;

int insert_robot(deque<int*> robots, int pos) {
	if (belt[pos] > 0) {
		robots.push_back(&belt[pos]);
		belt[pos]--;
		return pos;
	}
	return (-1);
}

bool check_zero(int pos) {
	if (belt[pos] == 0) {
		belt[pos]--;
		return true;
	}
	return false
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

	/* input */	
	cin >> N >> K;
	belt = new int[2 * N]{};
	for (int i=0; i<2*N; i++) cin >> belt[i];

	/* solve */
	int zero_cnt = 0, turn_cnt = 0;;
	int in = 0, out = N-1;
	int belt_len = 2 * N;
	deque<int*> robots;
	while (zero_cnt < K) {
		turn_cnt++;
		in = ((in - 1) + belt_len) % belt_len;
		out = ((out - 1) + belt_len) % belt_len;
		for (auto it = robots.begin(); it<robots.end(); it++) {
			if (**it > 0) {
				*it++;
				**it--;
				if (**it == 0) {
					zero_cnt++;
					**it = -1;
				}
			}
			if (*it == &belt[out])
				robots.erase(it);
		}
		int pos = insert_robot(robots, in);
		if (pos >= 0)
			zero_cnt += check_zero(pos);
	}
	cout << turn_cnt << "\n";
}
