// https://hio9105.tistory.com/entry/BOJ-5430-AC-deque-parsing-implementation-string-datastructures

#include <iostream>
#include <vector>

using namespace std;

#define FORWARD 1
#define REVERSE -1

struct AC {
	vector<string> nums;
	int begin, end;
	int flag;

	void init() {
		int n; 
		string input;
		cin >> n >> input;

		nums.clear();
		begin = 0; end = n-1;
		flag = FORWARD;	
		if (n == 0) return;
		for (auto e : input) {
			if ('0' <= e && e <= '9') nums.back() += e;
			else if (e == '[' || e == ',') nums.push_back("");
		}
	}

	bool cmd_R() {
		flag = -flag;
		return false;
	}

	bool cmd_D() {
		if (begin > end) return true;
		(flag == FORWARD) ? begin++ : end--; 
		return false;
	}

	void print_answer(bool isError) {
		if (isError) {
			cout << "error\n"; return;
		}
		cout << "[";
		if (begin <= end){
			if (flag == REVERSE) {
				int tmp = begin; begin = end; end = tmp;
			}
			for (auto it = begin; it != end; it += flag)
				cout << nums[it] << ",";
			cout << nums[end];
		}
		cout << "]\n";
	}
};

void solve(AC &ac) {
	string p; cin >> p;
	bool isError = false;
	ac.init();
	
	for (auto op : p) {
		switch(op) {
			case 'R':
				ac.cmd_R(); break;
			case 'D':
				isError = ac.cmd_D(); break;
		}
		if (isError) break;
	}
	ac.print_answer(isError);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	int TC; cin >> TC;
	AC ac;
	while (TC--) {
		solve(ac);
	} 	
}