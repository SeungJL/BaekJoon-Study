#include <iostream>
#include <vector>
#include <algorithm> // sort(), replace()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // init
    int N, L;
    cin >> N >> L;

    vector<int> X(N, 0);          // 물이 새는 곳의 위치 정보
    vector<bool> pipe(1001, 0);   // 파이프, 가장 왼쪽에서 i 만큼 떨어진 곳에 물이 샐 경우 → pipe[i] = true
    for (int i=0; i<N; i++) {
        cin >> X[i];
        pipe[X[i]] = true;
    }
    sort(X.begin(), X.end());    
    // 정렬해야 되는 이유 : 물이 새는 곳을 왼쪽에서부터 순차적으로 체크 + 테이프 남는 부분 오른족으로 붙여짐
    // 최소한의 테이프를 사용하기 위해서는 왼쪽에서부터 순차적으로 보면서 테이프의 중복 사용을 막아야 됨

    int tape_cnt = 0; // 사용된 테이프의 개수

    // solve
    for (auto x : X) {
        if (pipe[x]) {
            replace(pipe.begin() + x, pipe.begin() + x + L, true, false);
            tape_cnt++;
        }
    }

    cout << tape_cnt << "\n";
    
    return (0);
}