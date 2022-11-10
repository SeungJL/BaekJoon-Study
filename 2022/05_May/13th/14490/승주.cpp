#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int GCD(int, int);

int main() {
	string str;
	cin >> str;
	int a = stoi(str.substr(0, str.find(":")));
	int b = stoi(str.substr(str.find(":") + 1));
	int temp = GCD(a, b);
	cout << a / temp << ":" << b / temp;
}

int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}