#include <bits/stdc++.h>

using namespace std;

int N;
int result = 0;
int roma[] = {1, 5, 10, 50};

//50*20 = 1000(num의 최대값)
bool visited[1000 + 1];

void DFS(int cnt, int R, int num) {
    if (cnt == N) {
        //중복되는 숫자가 아니라면 result에 추가. 방문했다고 표시하기
        if (visited[num] == false) {
            visited[num] = true;
            result++;
        }
        return;
    }
    for (int i = R; i < 4; i++) {
        //roma 배열 안의 숫자들을 차례대로 더해서 재귀 돌리기.
        DFS(cnt + 1, i, num + roma[i]);
    }
}

int main() {
    scanf("%d", &N);
    DFS(0, 0, 0);
    printf("%d\n", result);
    return 0;
}
