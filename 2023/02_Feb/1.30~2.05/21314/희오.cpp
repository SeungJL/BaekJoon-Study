#include <iostream>

using namespace std;

void convert2num(int cnt, string &min, string &max) {
	if (!cnt) {
		min += '5'; max += '5';
		return ;
	}
	min += '1'; max += '5';
	while (--cnt) {
		min += '0'; max += '0';
	}
	min += '5'; max += '0';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// freopen("input.txt", "rt", stdin);

	string input;
	string min_num = "", max_num = "";

	cin >> input;
	int cnt = 0;
	for (auto ch : input) {
		switch (ch) {
			case 'M':
				cnt++;
				break;
			case 'K':
				convert2num(cnt, min_num, max_num);
				cnt = 0;
				break;
		}
	}
	if (cnt) {
		min_num += '1'; max_num += '1';
		while (--cnt) {
			min_num += '0'; max_num += '1';
		}
	}

	cout << max_num << "\n" << min_num << "\n";
}