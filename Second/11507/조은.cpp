#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	string input;
	char c;
	int a, b;
	int n;

	bool chk[4][13] = { false };
	int cnt[4] = { 0 };
	while (scanf("%c%1d%1d", &c, &a, &b) == 3) {
		n = 10 * a + b;
		int shape;
		switch (c) {
			case 'P': shape = 0; break;
			case 'K': shape = 1; break;
			case 'H': shape = 2; break;
			case 'T': shape = 3; break;
		}
		if (chk[shape][n - 1]) {
			cout << "GRESKA" << endl;
			return 0;
		}
		chk[shape][n - 1] = true;
		++cnt[shape];
	}

	for (int i = 0; i < 4; i++) {
		cout << 13 - cnt[i] << ' ';
	}

	return 0;
}
