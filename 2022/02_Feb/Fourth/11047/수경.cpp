#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    vector<int> V;
    for(int i=0;i<N;i++){
        int tmp;
        scanf("%d", &tmp);
        V.push_back(tmp);
    }
    int ans = 0;
    for(int i=N-1;i>=0;i--){
        //printf("V[%d]=%d\n", i, V[i]);
        if(K/V[i]>0){
            ans += K/V[i];
            K %= V[i];
        }
    }
    printf("%d", ans);
    return 0;
}