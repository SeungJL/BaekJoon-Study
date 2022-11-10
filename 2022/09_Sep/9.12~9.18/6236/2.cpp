#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> cost;

bool my_check(int K) {
    int cur = K, cnt = 1;
    for (auto c : cost) {
        if (cur < c) {
            cnt++;
            cur = K;
            if (cnt > M) break;
        }
        cur -= c;
    }

    if (cnt <= M) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    int input, max_cost = 0, sum = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> input;
        cost.push_back(input);
        if (input > max_cost) max_cost = input;
        sum += input;
    }

    int low = max_cost, high = sum + 1;
    int K = 0;
    int res = 1000000000;
    while (low <= high) {
        K = (low + high) / 2;
        if (K < res) {
            if (my_check(K)) {
                res = K;
                high = K - 1;
            }
            else {
                low = K + 1;
            }
        }
        else
            high = K - 1;
    }

    cout << res << "\n";
}
