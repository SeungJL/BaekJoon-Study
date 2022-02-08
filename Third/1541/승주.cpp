#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>
using namespace std;

int main() {
	string str;
	cin >> str;

	int sum = 0;
	int sum2 = 0;
	string s = "";
	int h = 0; // - 로 진행중
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-' || str[i] == '+') {
			if (h == 1) {
				sum -= stoi(s);
			}
			else {
				sum += stoi(s);
			}
			if (str[i] == '-') {
				h = 1;
			}
			s = "";
		}
		else {
			s += str[i]; // string에 + char 타입도 되는데?
		}
	}
	if (h == 1) {
		sum -= stoi(s);
	}
	else {
		sum += stoi(s);
	}
	cout << sum;
}
