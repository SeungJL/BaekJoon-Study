#include <iostream>
#include <vector>

using namespace std;

unsigned int K, N;
vector<unsigned int> cables;

int check_cnt(int len) {
    unsigned int cnt = 0;
    for(auto e : cables) {
        cnt += e / len;
    }
    return (cnt);
}

int solve(int S, int E) {
    unsigned int s = S, e = E; 
    unsigned int res_len = 0;
    while (s <= e) {
        unsigned int mid = (s + e) / 2;
        if (check_cnt(mid) < N) {
            e = mid - 1;
        }
        else {
            if (res_len < mid)
                res_len = mid;
            s = mid + 1;
        }
    }
    return (res_len);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    cin >> K >> N;

    unsigned int max_len = 0;
    for (int i=0; i<K; i++) {
        unsigned int input;
        cin >> input;
        cables.push_back(input);
        if (max_len < input)
            max_len = input;
    }
    
    cout << solve(1, max_len) << "\n";
}