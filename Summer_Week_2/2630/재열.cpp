#include <iostream>

using namespace std;

int N;
int white = 0, blue = 0;
bool table[128][128];

void check_and_divide(int x, int y, int len) {
	bool first = table[x][y];
	bool all_same = true;
	for (int x_move = 0; x_move < len; x_move++) {
		for (int y_move = 0; y_move < len; y_move++) {
			if (table[x+x_move][y+y_move] != first) {
				all_same = false;
				break;
			}
		}
	}
	if (all_same) {
		if (first == true) 
			blue++;
		else
			white++;
	}
	else {
		check_and_divide(x, y, len/2);
		check_and_divide(x, y+(len/2), len/2);
		check_and_divide(x+(len/2), y, len/2);
		check_and_divide(x+(len/2), y+(len/2), len/2);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> table[i][j];
		}
	}
	check_and_divide(0, 0, N);
	cout << white << '\n' << blue << endl;
	return 0;
}
