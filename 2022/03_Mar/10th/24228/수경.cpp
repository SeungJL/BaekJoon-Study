#include <bits/stdc++.h>

using namespace std;

int main(){
    long long N, R;
    scanf("%lld %lld", &N, &R);
    printf("%lld", 2*R+N-1);
    return 0;
}

/*
 * N+(R-1)*2+1
 *
 * N = 2, R = 1
 * ll
 * l
 * 3
 *
 * N = 2, R = 2
 * lll
 * ll
 * 2+2+1
 * 5
 *
 * N = 3, R = 1
 * ll
 * l
 * l
 * 4
 *
 * N = 3, R = 2
 * lll
 * ll
 * l
 * 6
 *
 * N = 3, R = 3
 * lll
 * lll
 * ll
 * 8
 *
 * N = 4, R = 1
 * ll
 * l
 * l
 * l
 * 4+1*1
 * 5
 *
 * N = 4, R = 2
 * lll
 * ll
 * l
 * l
 * 4+1*2+1
 * 7
 *
 * N = 4, R = 3
 * lll
 * lll
 * ll
 * l
 * 4 + 2*2+1
 * 9
 *
 */