#include <bits/stdc++.h>

using namespace std;

int N;
int S[20];
bool visited[2000001];

void DFS(int num, int index){
    // 백트랙킹 기법 사용
    visited[num] = true;
    if(index == N) return;

    // index번째 S를 더하지 않는 경우
    DFS(num, index+1);
    // index번째 S를 더하는 경우
    DFS(num+S[index], index+1);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++) cin >> S[i];
    DFS(0, 0);
    for(int i=1;i<2000001;i++){
        if(!visited[i]) {
            cout << i << "\n";
            break;
        }
    }


    return 0;
}
