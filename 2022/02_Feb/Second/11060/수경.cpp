#include <bits/stdc++.h>

using namespace std;

int maze[1000];
int N;

// 점프 횟수를 저장하는 배열
int jump[1000];

void solve(int i) {
    //인덱스가 끝(N번째)을 만나거나, 해당 인덱스가 0이면 빠꾸
    if (maze[i] == 0) return;

    //인덱스에 해당하는 원소의 숫자만큼 떨어진 칸을 탐색
    for (int j = 1; j <= maze[i]; j++) {
        //인덱스가 범위를 벗어나면 반복문 종료
        if (i + j > N) break;

        //0이면 무시하고 넘어가기
        if (maze[i + j] == 0) continue;

        //해당 인덱스에 해당하는 jump 배열의 점프 횟수가 아직 갱신되지 않았으면
        //현재까지의 점프 횟수에 1 더한 걸 저장.
        if (jump[i + j] == 0) {
            jump[i + j] = jump[i] + 1;
            //그리고 그 원소에서 또 점프 탐색하기에
            solve(i + j);
        }
        else {  //만약 이미 점프 횟수가 기록되어 있다면
            //이미 있던 수와 현재까지의 점프 횟수에 1 더한 것 중 더 '작은' 수를 jump 배열 기록
            if (jump[i + j] > jump[i] + 1) {
                jump[i + j] = jump[i] + 1;
                //그리고 그 원소에서 또 점프 탐색하기에
                solve(i + j);
            }
        }
    }
}


int main() {
    scanf("%d", &N);

    //미로 입력받기
    for (int i = 0; i < N; i++) {
        scanf("%d", &maze[i]);
    }

    solve(0);

    //원소 개수가 1개면 점프하지 않고 바로 도착
    if (N == 1) printf("0\n");
    else if (jump[N - 1] == 0) printf("-1\n");
    else printf("%d\n", jump[N-1]);

    return 0;
}