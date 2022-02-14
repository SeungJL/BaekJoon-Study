#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--){
        int N, M;
        scanf("%d %d", &N, &M);
        if(M-N<N) N = M-N;
        long long tmp = 1;
        for(int i=M;i>M-N;i--){
            tmp *= i;
        }
        for(int i=1;i<=N;i++) {
            tmp /= i;
        }
        printf("%d\n", tmp);
    }

    return 0;
}
