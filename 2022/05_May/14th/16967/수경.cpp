#include <bits/stdc++.h>

using namespace std;


int main(){
    int H, W, X, Y;
    scanf("%d %d %d %d", &H, &W, &X, &Y);

    int **B = new int*[H+X];
    for(int i=0;i<H+X;i++) B[i] = new int[W+Y];

    for(int i=0;i<H+X;i++) {
        for(int j=0;j<W+Y;j++){
            scanf("%d", &B[i][j]);
        }
    }

/*
 * 겹치는 범위
 * i X~H-1
 * j Y~W-1
 */

    for(int i=X;i<H;i++){
        for(int j=Y;j<W;j++){
            B[i][j] -= B[i-X][j-Y];
        }
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    return 0;
}
