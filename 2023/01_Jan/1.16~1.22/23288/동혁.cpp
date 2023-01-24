#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
int N, M, K;
int board[20][20];
int topS = 1;
int bottomS = 6;
int rightS = 3;
int leftS = 4;
int frontS = 5;
int backS = 2;
int rowPos = 0;
int colPos = 0;
int direction = 0;
int score = 0;
int dx[4] = {0 ,1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visited[20][20];

void moveEast() {
    int temp = bottomS;
    bottomS = rightS;
    rightS = topS;
    topS = leftS;
    leftS = temp;
}

void moveWest() {
    int temp = bottomS;
    bottomS = leftS;
    leftS = topS;
    topS = rightS;
    rightS = temp;
}

void moveNorth() {
    int temp = bottomS;
    bottomS = backS;
    backS = topS;
    topS = frontS;
    frontS = temp;
}

void moveSouth() {
    int temp = bottomS;
    bottomS = frontS;
    frontS = topS;
    topS = backS;
    backS = temp;
}

void roll(int n) {
    if(n == 0) {
        if(colPos + 1 >= M) {
            direction = (direction + 2) % 4;
            colPos--;
            moveWest();
            return;
        }
        colPos++;
        moveEast();
    } else if(n == 1) {
        if(rowPos + 1 >= N) {
            direction = (direction + 2) % 4;
            rowPos--;
            moveNorth();
            return;
        }
        rowPos++;
        moveSouth();
    } else if(n == 2) {
        if(colPos - 1 < 0) {
            direction = (direction + 2) % 4;
            colPos++;
            moveEast();
            return;
        }
        colPos--;
        moveWest();
    } else {
        if(rowPos - 1 < 0) {
            direction = (direction + 2) % 4;
            rowPos++;
            moveSouth();
            return;
        }
        rowPos--;
        moveNorth();
    }
}

void changeDirection() {
    if(bottomS > board[rowPos][colPos]) {
        direction = (direction + 1) % 4;
    } else if(bottomS < board[rowPos][colPos]) {
        direction = (direction + 3) % 4;
    }
    return;
}

void dfs(int x, int y, int number) {
    if(x < 0 || x >= N || y < 0 || y >= M) {
        return;
    }

    if(visited[x][y]) {
        return;
    }

    if(board[x][y] != number) {
        return;
    } 
    visited[x][y] = true;
    score += number;
    for(int i = 0; i < 4; i++) {
        int xPos = x + dx[i];
        int yPos = y + dy[i];
        dfs(xPos, yPos, number);
    }
    return;
}
int main() {
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    // East
    

    //
    for(int i = 0; i < K; i++) {
        // roll the dice
        roll(direction);
        changeDirection();
        // cout << rowPos << " " << colPos;
        dfs(rowPos, colPos, board[rowPos][colPos]);
        memset(visited, false, sizeof(visited));
    }

    cout << score;
    return 0;
}