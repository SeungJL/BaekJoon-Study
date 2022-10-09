// 1107

#include <iostream>

using namespace std;

int N, M;
bool broken[10] = {};

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

    freopen("input.txt", "rt", stdin);

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int input;
        cin >> input;
        broken[input] = true;        
    }


    int res = (N - 100 >= 0) ? N - 100 : 100 - N;

    if (res == 0 || M == 10) {
        cout << res << "\n";
        return 0;
    }

    int digit;
    for (int n=N; n>=0; n--) {
        digit = check_working(n);
        if (digit >= 0) {
            if (digit + (N - n) <= res) res = digit + (N - n);
        }
    }

    for (int n=N; n<=1000000; n++) {
        digit = check_working(n);
        if (digit >= 0) {
            if (digit + (n - N) <= res) res = digit + (n - N);
        }
    }

    cout << res << "\n";

}
