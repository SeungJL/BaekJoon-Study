// https://hio9105.tistory.com/entry/BOJ-5397-%ED%82%A4%EB%A1%9C%EA%B1%B0-datastructures-linkedlist-stack

#include <iostream>
#include <vector>

using namespace std;

class Keylogger {
	vector<char> left;
	vector<char> right;

public:
	void add(char c) {	// insert one letter
		left.push_back(c);
	}
	void del() {		// backspace, delete one letter
		if (!left.empty())
			left.pop_back();
	}
	void to_left() {	// move cursor to left
		if (!left.empty()) {
			char tmp = left.back(); left.pop_back();
			right.push_back(tmp);
		}
	}
	void to_right() {	// move cursor to right
		if (!right.empty()) {
			char tmp = right.back(); right.pop_back();
			left.push_back(tmp);
		}	
	}
	string get_password() {	// return password found by keylogger
		string res = "";

		for (auto e : left)
			res += e;
		for (auto it = right.rbegin(); it != right.rend(); it++)
			res += *it;
		
		return res;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "rt", stdin);

	int TC;
	cin >> TC;

	while (TC--) {
    	/* input */
		string input;
		cin >> input;

		/* solve */
		Keylogger keylogger;
		for (auto e : input) {
			switch (e) {
				case '-':
					keylogger.del(); break;
				case '<':
					keylogger.to_left(); break; 
				case '>':
					keylogger.to_right(); break;
				default:
					keylogger.add(e);
			}
		}
        
        /* print answer */
		cout << keylogger.get_password() << "\n";
	}
}