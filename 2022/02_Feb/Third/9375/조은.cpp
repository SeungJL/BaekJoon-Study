#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	int T;
	cin >> T;
	int n;
	string s[2];
	for (int i = 0; i < T; i++) {
		cin >> n;
		unordered_map<string, int> umap;
		while (n--) {
			cin >> s[0] >> s[1];
			if (umap.find(s[1]) != umap.end()) {
				++umap[s[1]];
			}
			else {
				umap.insert({ s[1], 1 });
			}
		}

		int ans = 1;
		for (auto i = umap.begin(); i != umap.end(); i++) {
			ans *= (i->second + 1);
		}
		cout << --ans << endl;
	}

	return 0;
}
