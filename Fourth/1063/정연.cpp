#include <iostream>
#include <string>

using namespace std;


// r, l, b, t, rt, lt, rb, lb
int dx[8] = {0, 0, +1, -1, -1, -1, +1, +1};
int dy[8] = {+1, -1, 0, 0, +1, -1, +1, -1};
int d=0;

int main() {
	
	string king, stone;
	int n;
	
	cin >> king >> stone >> n;
	
    char kx = king[0], ky = king[1];
    char sx = stone[0], sy = stone[1];
    
    string move;

	for (int i = 0; i < n; i++) {
		
		cin >> move;
		
		int d = 0;
		if (move == "R") {

		}
		else if (move == "L") {
			d += 1;
		}
		else if (move == "B") {
			d += 2;
		}
		else if (move == "T") {
			d += 3;
		}
		else if (move == "RT") {
			d += 4;
		}
		else if (move == "LT") {
			d += 5;
		}
		else if (move == "RB") {
			d += 6;
		}
		else {
			d += 7;
		}
		int nx = kx + dx[d];
		int ny = ky + dy[d];
		
		if (nx < '1' || nx > '8' || ny < 'A' || ny > 'H' ) {
			continue;
		}
		
		if (nx == sx && ny == sy) {
			int mx = sx + dx[d];
			int my = sy + dy[d];
		
			if (mx < '1' || mx > '8' || my < 'A' || my > 'H') {
				continue;
			}
			else {
				
				sx = mx; sy = my;
			}
		}
		
		kx = nx; ky = ny;
	}
	cout << kx << ky << "\n" << sx << sy <<"\n";
	return 0;
}
