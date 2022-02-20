#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int n, k;
	cin >> n >> k;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	set<string> s;
	string str = "";
	switch (k) {

	case 2:
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == i) continue;
				str += v[i] + v[j];
				s.insert(str);
				str = "";
			}
		}
		break;

	case 3:
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (i == j || j == k || k == i) continue;
					str += v[i] + v[j] + v[k];
					s.insert(str);
					str = "";
				}
			}
		}
		break;

	case 4:
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					for (int l = 0; l < n; l++) {
						if (i == j || i == k || i == l || j == k || j == l || k == l) continue;
						str += v[i] + v[j] + v[k] + v[l];
						s.insert(str);
						str = "";
					}
				}
			}
		}
		break;
	}

	cout << s.size();

	return 0;
}