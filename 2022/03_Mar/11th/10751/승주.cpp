#include <iostream>
#include <cmath>
#include <map>
#include <string>

using namespace std;

int main() {
	string str;
	int N;
	long long C = 0, W = 0, O = 0;
	cin >> N;
	cin >> str;
	char s;
	for (int i = str.size() - 1; i >= 0; i--) {
		s = str[i];
		if (s == 'W') { W++; }
		else if (s == 'O') { O += W; }
		else if (s == 'C') { C += O; }
	}
	cout << C;
}