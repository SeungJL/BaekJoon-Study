#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    // 위에 껍데기
    for (int j = 0; j < N; j++) printf("*");
    int widthGap = (N - 1) * 2 - 1;
    for (int j = 0; j < widthGap; j++) printf(" ");
    for (int j = 0; j < N; j++) printf("*");
    printf("\n");

    // 상단 X
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < i + 1; j++) printf(" ");
        printf("*");
        for (int j = 0; j < N - 2; j++) printf(" ");
        printf("*");
        for (int j = 0; j < (N - (i + 1)) * 2 - 3; j++) printf(" ");
        printf("*");
        for (int j = 0; j < N - 2; j++) printf(" ");
        printf("*\n");
    }

    // 중간 X
    for (int i = 0; i < N - 1; i++) printf(" ");
    printf("*");
    for (int j = 0; j < N - 2; j++) printf(" ");
    printf("*");
    for (int j = 0; j < N - 2; j++) printf(" ");
    printf("*\n");

    // 하단 X
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < N - (i + 2); j++) printf(" ");
        printf("*");
        for (int j = 0; j < N - 2; j++) printf(" ");
        printf("*");
        for (int j = 0; j < i * 2 + 1; j++) printf(" ");
        printf("*");
        for (int j = 0; j < N - 2; j++) printf(" ");
        printf("*\n");

    }

    // 아래 껍데기
    for (int j = 0; j < N; j++) printf("*");
    for (int j = 0; j < widthGap; j++) printf(" ");
    for (int j = 0; j < N; j++) printf("*");
    return 0;
}