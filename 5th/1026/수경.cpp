#include <bits/stdc++.h>

using namespace std;

vector<int> A;
vector<int> B;

int main() {
    int N;
    scanf("%d", &N);


    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        A.push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        B.push_back(tmp);
    }

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i] * B[i];
    }
    printf("%d", sum);

    return 0;
}
