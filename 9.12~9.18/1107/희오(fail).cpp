// 1107

#include <iostream>
#include <queue>

using namespace std;

int N, M;
bool broken[10] = {};
int res;

int check_working(int n) {
    if (n == 0)
        return (broken[0]) ? -1 : 1;

    int tmp, cnt = 0;
    while (n) {
        cnt++;
        tmp = n % 10;
        if (broken[tmp]) return -1;
        n /= 10;
    }
    return cnt;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int input;
        cin >> input;
        broken[input] = true;        
    }


    res = (N - 100 >= 0) ? N - 100 : 100 - N;

    if (res == 0 || M == 10) {
        cout << res << "\n";
        return 0;
    }


    queue<pair<int, int>> Q;
    Q.push(make_pair(N, 0));
    while (!Q.empty()) {
        int n = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();

        int digit = check_working(n);
        if (digit >= 0) {
            (digit + cnt <= res) ? cout << digit + cnt << "\n" : cout << res << "\n";
            return 0;
        }

        Q.push(make_pair(n+1, cnt+1));
        if (n-1 >= 0) Q.push(make_pair(n-1, cnt+1));

    }

}
