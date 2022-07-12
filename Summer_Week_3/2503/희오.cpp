#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> Q;

/* 민혁이가 말한 숫자와 주어진 스트라이크, 볼 정보에 일치하는 숫자인지 확인하는 함수
 *
 * N1-민혁이가 말한 숫자, N2-일치여부를 확인할 숫자, s-스트라이크 정보, b-볼 정보
 * N1에서 사용된 숫자와 사용된 위치를 ch_n1에 체크한 후, 
 * 그 정보를 N2에 사용된 숫자와 비교하여 스트라이크/볼 여부를 체크
 * N1, N2의 스트라이크와 볼 정보가 주어진 s, b와의 일치 여부를 리턴 (일치-true, 불일치-false)
 */
bool check_sb(int N1, int N2, int s, int b) {
    int n1 = N1, n2 = N2;
    vector<int> ch_n1(10, -1);

    for (int i=2; i>=0; i--) {
        ch_n1[n1%10] = i;
        n1 /= 10;
    }

    for (int i=2; i>=0; i--) {
        if (ch_n1[n2%10] == i) s--;
        else if (ch_n1[n2%10] != -1) b--;
        n2 /= 10;
    }

    if (!s && !b) return true;
    else return false;
}

/* queue 'Q'를 초기화하는 함수
 *
 * 1~9 숫자 중 서로 다른 숫자 세 개로 구성된 세 자리 수를 모두 Q에 넣음
 * DFS 이용 (k-자릿수, num-k개의 숫자로 구성된 k자리 수, visited-num에 사용된 숫자 체크)
 */
void init_Q(int k, int num, int visited) {
    if (k == 3) {
        Q.push(num);
        return;
    }

    for(int i=1; i<=9; i++) {
        if ((visited & (1 << i)) == 0) {
            init_Q(k + 1, num * 10 + i, visited | (1 << i));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    init_Q(0, 0, 0);

    int N;
    cin >> N;

    while (N--) {
        int num, s, b;
        cin >> num >> s >> b;
        int q_size = Q.size();
        while (q_size--) {
            int front = Q.front();
            Q.pop();
            if (check_sb(num, front, s, b)) 
                Q.push(front);
        }
    }
    
    cout << Q.size() << "\n";
    return 0;
}