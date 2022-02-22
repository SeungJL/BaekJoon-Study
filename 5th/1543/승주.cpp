#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>

using namespace std;

int main() {
	string str;
	string ans;
	getline(cin, str);
	getline(cin, ans);

	int a = 0;
	int cnt = 0;
	while (1) {
		a = str.find(ans, a);
		if (a == string::npos) { break; }
		else { a += ans.size(); }
		cnt++;
	}
	cout << cnt;
}