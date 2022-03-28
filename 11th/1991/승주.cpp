#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

vector <vector <int>> V(100);
map <int, int> m;

void Front(int start) {
	cout << char(start + 64);
	for (int i = 0; i < 2; i++) {
		if (V[start][i] != 0) {
			Front(V[start][i]);
		}
	}
}


void Middle(int start) {
	for (int i = 0; i < 2; i++) {
		if (V[start][i] != 0) {
			Middle(V[start][i]);
		}
		if (i == 0) {
			cout << char(start + 64);
		}
	}
}

void End(int start) {
	for (int i = 0; i < 2; i++) {
		if (V[start][i] != 0) {
			End(V[start][i]);
		}
	}
	cout << char(start + 64);
}

int main() {
	int N;
	char a, b, c;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		if (b == '.') { b = '@'; }
		if (c == '.') { c = '@'; }
		V[int(a - 64)].push_back(int(b - 64));
		V[int(a - 64)].push_back(int(c - 64));
		m[int(b - 64)] = int(a - 64);
		m[int(c - 64)] = int(a - 64);
	}
	Front(1);
	cout << endl;
	Middle(1);
	cout << endl;
	End(1);
}