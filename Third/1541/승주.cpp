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
	int h = 0; // - �� ������
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
			s += str[i]; // string�� + char Ÿ�Ե� �Ǵµ�?
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
