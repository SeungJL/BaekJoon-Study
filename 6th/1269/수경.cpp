#include <bits/stdc++.h>

using namespace std;

map<int, int> M;
vector<int> A, B;

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    for (int i = 0; i < b; i++) {
        int tmp;
        cin >> tmp;
        B.push_back(tmp);
    }

    for (int i = 0; i < a; i++) {
        M[A[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < b; i++) {
        if (M[B[i]] > 0) ans++;
    }

    cout << a + b - ans * 2;


    return 0;
}
/*
 * 1 2 4
 * 2 3 4 5 6
 *
 *
 */

/*
3 6
1 2 4
2 2 3 4 5 6

 1 2 4


 */