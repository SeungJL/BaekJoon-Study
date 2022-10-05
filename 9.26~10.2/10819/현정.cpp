#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int tem;
        cin >> tem;
        arr.push_back(tem);
    }

    int ret = 0;
    sort(arr.begin(), arr.end());
    do {
        int tem = 0;
        for (int i = 0; i < arr.size() - 1; i++)
            tem += abs(arr[i] - arr[i + 1]);

        ret = max(ret, tem);
    } while (next_permutation(arr.begin(), arr.end()));

    cout << ret << "\n";

    return 0;
}
//승현 to 현정
