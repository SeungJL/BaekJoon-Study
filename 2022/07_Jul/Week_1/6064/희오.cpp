#include <iostream>

using namespace std;

// 최대공약수를 구하는 함수
/* 유클리드 호제법을 이용
    1. 큰 숫자(a)를 작은 숫자(b)로 mod 연산을 한다. (c = a mod b)
    2. 작은 숫자(b)를 1번에서 구한 나머지(c)로 mod 연산을 한다. (new_c = b mod c)
    3. 위 과정을 mod 연산의 결과가 0이 나올때 까지 계속 반복한다.
    4. mod 연산의 결과가 0이 됐을 때 나누는 수로 사용된 수가 두 수의 최대공약수가 된다.
*/
int get_gcd(int a, int b) {
    if (a < b) {
        int tmp = a;
        a = b; 
        b = tmp;
    }

    int mod = a % b;
    while (mod != 0) {
        a = b;
        b = mod;
        mod = a % b;
    }
    return (b);
}

int solve(int M, int N, int x, int y) {
    int gcd = get_gcd(M, N);
    int max_a = N / gcd, max_b = M / gcd;
    int a = 0, b = 0;
    while (a <= max_a && b <= max_b) {
        int res1 = a * M + x;
        int res2 = b * N + y;

        if (res1 == res2) 
            return (res1);
        else 
            (res1 < res2) ? a++ : b++;
    }
    return (-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    int T;
    cin >> T;

    for (int t=0; t<T; t++) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        cout << solve(M, N, x, y) << "\n";
    }
}