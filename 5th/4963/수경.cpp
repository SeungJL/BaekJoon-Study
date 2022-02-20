#include <bits/stdc++.h>

using namespace std;

int island[50][50];

int x[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int y[8] = {1, 0, -1, 1, -1, 1, 0, -1};

void paint(int _i, int _j, int w, int h) {
    island[_i][_j] = 0;
    for (int i = 0; i < 8; i++) {
        int new_x = x[i] + _i;
        int new_y = y[i] + _j;
        //printf("newx=%d, newy=%d\n", new_x, new_y);
        if (0 <= new_x && new_x < h && 0 <= new_y && new_y < w) {
            if (island[new_x][new_y] == 1) paint(new_x, new_y, w, h);
        }
    }

}

int main() {

    while (true) {

        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> island[i][j];
            }
        }

        int cnt = 0;


        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (island[i][j] == 1) {
                    paint(i, j, w, h);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}