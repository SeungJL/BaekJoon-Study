#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int kx, ky, sx, sy, N;
bool rangeCheck(int x, int y);
bool stoneCheck(void);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "rt", stdin);
	char k, s;
	cin >> k >> ky;
	kx = k - 'A' + 1;
	cin >> s >> sy;
	sx = s - 'A' + 1;
	cin >> N;

	while (N--) {
		string dir;
		cin >> dir;
		if (dir == "R") { // 오른쪽
			if (rangeCheck(kx + 1, ky)) {
				kx++;
				if (stoneCheck()) {
					if (rangeCheck(kx + 1, ky)) sx++;
					else kx--;
				}
			}
		}
		else if (dir == "L") { // 왼쪽
			if (rangeCheck(kx - 1, ky)) {
				kx--;
				if (stoneCheck()) {
					if (rangeCheck(kx - 1, ky)) sx--;
					else kx++;
				}
			}
		}
		else if (dir == "B") { // 아래
			if (rangeCheck(kx, ky - 1)) {
				ky--;
				if (stoneCheck()) {
					if (rangeCheck(kx, ky - 1)) sy--;
					else ky++;
				}
			}
		}
		else if (dir == "T") { // 위
			if (rangeCheck(kx, ky + 1)) {
				ky++;
				if (stoneCheck()) {
					if (rangeCheck(kx, ky + 1)) sy++;
					else ky--;
				}
			}
		}
		else if (dir == "RT") { // 오른쪽 위 대각선
			if (rangeCheck(kx + 1, ky + 1)) {
				kx++; ky++;
				if (stoneCheck()) {
					if (rangeCheck(kx + 1, ky + 1)) {
						sx++; sy++;
					}
					else {
						kx--; ky--;
					}
				}
			}
		}
		else if (dir == "LT") { // 왼쪽 위 대각선
			if (rangeCheck(kx - 1, ky + 1)) {
				kx--; ky++;
				if (stoneCheck()) {
					if (rangeCheck(kx - 1, ky + 1)) {
						sx--; sy++;
					}
					else {
						kx++; ky--;
					}
				}
			}
		}
		else if (dir == "RB") { // 오른쪽 아래 대각선
			if (rangeCheck(kx + 1, ky - 1)) {
				kx++; ky--;
				if (stoneCheck()) {
					if (rangeCheck(kx + 1, ky - 1)) {
						sx++; sy--;
					}
					else {
						kx--; ky++;
					}
				}
			}
		}
		else if (dir == "LB") { // 왼쪽 아래 대각선
			if (rangeCheck(kx - 1, ky - 1)) {
				kx--; ky--;
				if (stoneCheck()) {
					if (rangeCheck(kx - 1, ky - 1)) {
						sx--; sy--;
					}
					else {
						kx++; ky++;
					}
				}
			}
		}
	}

	char _k = kx + 'A' - 1;
	char _s = sx + 'A' - 1;
	cout << _k << ky << '\n' << _s << sy;

	return 0;
}

bool rangeCheck(int x, int y) {
	if (x < 1 || x > 8 || y < 1 || y > 8) return false;
	return true;
}

bool stoneCheck(void) {
	if (kx == sx && ky == sy) return true;
	else return false;
}