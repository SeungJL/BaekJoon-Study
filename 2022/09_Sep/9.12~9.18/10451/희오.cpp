// 10451 

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        int input[1001] = {};

        cin >> N;
        for (int i=1; i<=N; i++) cin >> input[i];

        int cnt = 0;
        for (int i=1; i<=N; i++) {
            if (!input[i]) continue;
            cnt++;
            int tmp = i, tmp2;
            while (input[tmp]) {
                tmp2 = input[tmp];
                input[tmp] = 0;
                tmp = tmp2;
            }
        }

        cout << cnt << "\n";
    }
    
}