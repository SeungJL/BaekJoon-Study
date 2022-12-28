#include <iostream>

using namespace std;

int cnt = 0;
int N, M, r, c, d;
int arr[51][51] = {};
bool visit[51][51] = {};
void cleanerMove(int a, int b, int d) {
    int xMove = 0, yMove = 0;
    if (visit[a][b] == 0) {
        cnt++;
        visit[a][b] = 1;
    }
    int check = 0;
    while (1) {
        if (check == 4) {
            xMove = -xMove;
            yMove = -yMove;
            if (arr[a + yMove][b + xMove] == 1) {
                return;
            }
            a += yMove;
            b += xMove;
            break;
        }
        xMove = 0; yMove = 0;
        if (d == 0) xMove = -1;
        else if (d == 1) yMove = -1;
        else if (d == 2) xMove = 1;
        else yMove = 1;
        d--;
        if (d == -1) d = 3;
        if (visit[a + yMove][b + xMove] == 0 && arr[a + yMove][b + xMove] == 0) {
            a += yMove;
            b += xMove;
            break;
        }
        check++;
    }
    cleanerMove(a, b, d);

}

int main()
{

    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    cleanerMove(r, c, d);
    cout << cnt;

}