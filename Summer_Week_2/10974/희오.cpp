#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> ch(9, false);
vector<int> res;

void dfs(int k) {
    if (k == N) {
        for (auto e : res) 
            cout << e << " ";
        cout << "\n";
        return;
    }

    for (int i=1; i<=N; i++) {
        if (!ch[i]) {
            ch[i] = true;
            res.push_back(i);
            dfs(k+1);
            ch[i] = false;
            res.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> N;
    dfs(0);
}

/* using next_permutation()
#include <iostream>
#include <vector>
#include <algorithm> // next_permutation

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr;
    for (int i=1; i<=N; i++) arr.push_back(i);

    do {
        for (auto e : arr) cout << e << " ";
        cout << "\n";
    } while (next_permutation(arr.begin(), arr.end()));

}
*/