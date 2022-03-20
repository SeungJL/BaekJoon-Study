#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int joker = 1;


    for (int i = 0; i < N; i++) {
        char where = 'r';   //처음에 오른쪽부터 합치기 시작
        char joker_where = 'l';

        if (joker > 13) {
            joker_where = 'r';
            joker -= 13;
        }

        vector<int> A;
        int sum = 0;
        while (sum < 27) {
            int tmp;
            scanf("%d", &tmp);
            sum += tmp;
            A.push_back(tmp);
        }

        int cur = 0;
        for (int i = 0; i < A.size(); i++) {
            if (where == 'r') {
                where = 'l';
                if (joker_where == 'l') cur += A[i];
                else {
                    if (joker <= A[i]) {
                        joker += cur;
                        break;
                    } else cur += A[i];
                }
            } else {   // where == 'l'
                where = 'r';
                if (joker_where == 'r') cur += A[i];
                else {
                    if (joker <= A[i]) {
                        joker += cur;
                        break;
                    } else cur += A[i];
                }
            }
        }
    }
    printf("%d\n", joker);

    return 0;
}