#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > paper(130, vector<int>(130, 0));
// vector< vector<int> > dia_sum(130, vector<int>(130, 0));
int blue_cnt = 0, white_cnt = 0;

/* 
// using DP
bool check_square(int r1, int c1, int N, bool flag) {
    int r2 = r1 + N - 1, c2 = c1 + N - 1;
    int i;
    for (i = 0; i < N - 1; i++) {
        if (dia_sum[r2-i][c2] - dia_sum[r1][c1+i] != (N - i - 1) * flag) break;
        if (dia_sum[r2][c2-i] - dia_sum[r1+i][c1] != (N - i - 1) * flag) break; 
    }
    if (i == N - 1) {
        if (paper[r1][c2] == flag && paper[r2][c1] == flag)
            return true;
    }
    return false;
}
*/

// 주어진 범위의 색이 동일한지 확인하는 함수
// (r, c)에서부터 N만큼 즉, (r+N, c+N)까지를 범위로 함
// flag = (r, c)의 색
// 색이 모두 동일하면 true, 하나라도 다를 경우 false를 리턴
bool check_square(int r, int c, int N, bool flag) {
    for (int i = r; i < r + N; i++) {
        for (int j = c; j < c + N; j++) {
            if (paper[i][j] != flag) return false;
        }
    }
    return true;
}

// 분할정복으로 문제를 푸는 재귀함수
// check_square()를 통해 주어진 부분 ( (r, c) ~ (r+N, c+N) )의 색이 모두 동일한지 확인한 후
// 같을 경우 해당 색의 개수를 증가
// 다를 경우 종이를 4등분하여 재귀함수 호출
void solve(int r, int c, int N) {
    bool flag = (paper[r][c] == 0) ? 0 : 1;
    if (N == 1 || check_square(r, c, N, flag)) {
        (flag) ? blue_cnt++ : white_cnt++;
        return;
    }

    solve(r, c, N/2);
    solve(r, c + N/2, N/2);
    solve(r + N/2, c, N/2);
    solve(r + N/2, c + N/2, N/2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "rt", stdin);

    int N;
    cin >> N;

    for (int r=1; r<=N; r++) {
        for (int c=1; c<=N; c++) {
            cin >> paper[r][c];
            // dia_sum[r][c] = dia_sum[r-1][c-1] + paper[r][c];
        }
    }

    solve(1, 1, N);
    cout << white_cnt << "\n" << blue_cnt << "\n";
}