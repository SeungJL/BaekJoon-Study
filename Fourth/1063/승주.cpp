#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	int K_x, K_y;
	int D_x, D_y;

	map<char, int> m;
	m.insert({ 'A', 0 });
	m.insert({ 'B', 1 });
	m.insert({ 'C', 2 });
	m.insert({ 'D', 3 });
	m.insert({ 'E', 4 });
	m.insert({ 'F', 5 });
	m.insert({ 'G', 6 });
	m.insert({ 'H', 7 });

	char c;

	cin >> c >> K_y;
	K_x = m[c];
	K_y--;
	cin >> c >> D_y;
	D_x = m[c];
	D_y--;
	int N;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		int a = 0;
		int b = 0;
		int h = 0;
		if (str == "R") {
			a++;
		}
		else if (str == "L") {
			a--;
		}
		else if (str == "B") {
			b--;
		}
		else if (str == "T") {
			b++;
		}
		else if (str == "RT") {
			a++; b++;
		}
		else if (str == "LT") {
			a--; b++;
		}
		else if (str == "RB") {
			a++; b--;
		}
		else {
			a--; b--;
		}
		K_x += a;
		K_y += b;
		if (K_x == D_x && K_y == D_y) {
			D_x += a;
			D_y += b;
			h = 1;
		}
		if (K_x < 0 || K_x>7 || K_y < 0 || K_y>7 || D_x < 0 || D_x>7 || D_y < 0 || D_y>7) {
			K_x -= a;
			K_y -= b;
			if (h == 1) {
				D_x -= a;
				D_y -= b;
			}
		}
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == K_x) {
			cout << iter->first << K_y + 1 << endl;
			break;
		}
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == D_x) {
			cout << iter->first << D_y + 1 << endl;
		}
	}
}
