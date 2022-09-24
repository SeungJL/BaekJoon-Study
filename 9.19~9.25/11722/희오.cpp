#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "rt", stdin);

    int N, res = 0;
    int nums[1000] = {};
    int cnt[1000] = {};

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> nums[i];
    }

    for (int i=N-1; i>=0; i--) {
        for (int j=i+1; j<N; j++) {
            if (nums[i] > nums[j] && cnt[i] < cnt[j]) {
                cnt[i] = cnt[j];
            }
        }
        cnt[i]++;
        if (cnt[i] > res) res = cnt[i];
    }

    cout << res << "\n";
    
}