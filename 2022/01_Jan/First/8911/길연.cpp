// 백준 8911번 거북이문제 2022년 01월 24일
#include <iostream>

using namespace std;

int main() {

	int x[] = { 0, 1, 0, -1 }; // 북F 동R 남B 서L (오른쪽 회전) 
	int y[] = { 1, 0, -1, 0 };

	int test_N = 0;
	cin >> test_N;

	while (test_N--) {
		int cx = 0, cy = 0; // 현재 x, y좌표
		int rot = 0; // 현재 방향 

		int maxX = 0, maxY = 0, minX = 0, minY = 0;

		string route; 
		cin >> route;

		for (int i = 0; i < route.size(); i++) {
			char c = route[i];
			if (c == 'L' || c == 'R') {  // 방향전환
				if (c == 'L')
					rot = (rot + 3) % 4; // 3(Xvalue: -1) 6(0)  9(1)
				else
					rot = (rot + 1) % 4; 
			}
			else {  // 이동
				if (c == 'F') {
					cx += x[rot];
					cy += y[rot];
				}
				else { // c == 'B'
					cx -= x[rot];
					cy -= y[rot];
				}
				maxX = max(cx, maxX);
				maxY = max(cy, maxY);
				minX = min(cx, minX);
				minY = min(cy, minY);
			}	
		}
		int width = (maxX - minX) * (maxY - minY);
		cout << width << endl;
	}
	return 0;
}
