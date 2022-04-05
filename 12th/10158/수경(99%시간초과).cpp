#include <bits/stdc++.h>

using namespace std;

// 오른쪽 위, 왼쪽 위, 왼쪽 아래, 오른쪽 아래
int dx[] = {1, -1, -1, 1};
int dy[] = {1, 1, -1, -1};


int main() {
    int w, h;
    scanf("%d %d", &w, &h);
    int p, q;
    scanf("%d %d", &p, &q);
    int t;
    scanf("%d", &t);

    int x = p, y = q;
    int cur = 0;
    while (t > 0) {
        if (cur == 0) {
            int tmp = min((h - y), (w - x));
            if (tmp > t) tmp = t;
            t -= tmp;
            x += dx[cur] * tmp;
            y += dy[cur] * tmp;
            if (h - y < w - x) {
                cur = 3;
            }
            else if (h - y > w - x) {
                cur = 1;
            }
            else {
                cur = 2;
            }
        } else if (cur == 1) {
            int tmp = min((h - y), (x));
            if (tmp > t) tmp = t;
            t -= tmp;
            x += dx[cur] * tmp;
            y += dy[cur] * tmp;
            if (h - y < x) {
                cur = 2;
            }
            else if (h - y > x) {
                cur = 0;
            }
            else {
                cur = 3;
            }
        } else if (cur == 2) {
            int tmp = min((y), (x));
            if (tmp > t) tmp = t;
            t -= tmp;
            x += dx[cur] * tmp;
            y += dy[cur] * tmp;
            if (y < x) {
                cur = 1;
            }
            else if (y > x) {
                cur = 3;
            }
            else {
                cur = 0;
            }
        } else if (cur == 3) {
            int tmp = min((y), (w - x));
            if (tmp > t) tmp = t;
            t -= tmp;
            x += dx[cur] * tmp;
            y += dy[cur] * tmp;
            if (y < w - x) {
                cur = 0;
            }
            else if (y > w - x) {
                cur = 2;
            }
            else {
                cur = 1;
            }
        }
    }


    printf("%d %d\n", x, y);
    return 0;
}