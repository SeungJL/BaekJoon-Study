#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	string input;
	cin >> input;
	int len = input.size();
	
	string n;
	int ans = 0;
	bool flag = false;
	for (int i = 0; i <= len; i++) {
		if (input[i] == '-' || input[i] == '+' || input[i] == '\0') {
			if (flag) {
				ans -= stoi(n);
				n = "";
			}
			else {
				ans += stoi(n);
				n = "";
			}

			if (input[i] == '-') { flag = true; }
		}
		else {
			n = n + input[i];
		}
	}
	cout << ans;

	return 0;
}
